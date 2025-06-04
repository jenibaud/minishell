#ifndef MINISHELL_H
# define MINISHELL_H

/*##############################################*/
/*					Includes					*/
/*##############################################*/

# include <libft/inc/libft.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <utmp.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <stdbool.h>

/*##############################################*/
/*					Defines						*/
/*##############################################*/

# define CODE_CTRL_C 130
# define CODE_NOT_FOUND 127
# define CODE_NOT_EXEC 126
# define CODE_ERROR 1
# define CODE_BADFD 0
# define SIMPLEQ 39
# define DOUBLEQ 34

/*##############################################*/
/*					Commands					*/
/*##############################################*/

# define EXIT "exit";

/*##############################################*/
/*					Structs						*/
/*##############################################*/

typedef struct s_env
{
	char	**export;
	char 	**env;
} t_env;

typedef enum e_type
{
	WORD, // 0
	PIPE, // 1
	REDIR_IN, // 2
	REDIR_OUT, // 3
	HEREDOC, // 4
	APPEND, // 5
} t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*next;
} t_token;

typedef struct s_cmd
{
	char			**cmd;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
} t_cmd;

typedef enum e_type
{
	CMD,
	PIPE,
	FILENAME,
	REDIR_IN,
	REDIR_OUT,
	QUOTES,
	DQUOTES,
	HEREDOC,
	APPEND,
	STR_ARG,
	B_EXIT,
} t_type;

typedef struct s_token
{
	char	*value;
	t_type	type;
} t_token;

typedef struct s_data
{
	char	**env;
	char	**cmd; // cmd[0] will always be the command to execute anyways (cmd[0] = wc, cmd[1] = -l ...)
	char	*path;
	int		infile;
	int		outfile;
	int		exit_code;
	pid_t	*pid;
} t_data;

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;

/*##############################################*/
/*					Functions					*/
/*##############################################*/

void	parsing(char *rl, t_data **data, char **env);
void	init_struct(t_data **data);
void	alloc_data(int data_size, t_data **data);

/*##############################################*/
/*					Built-ins					*/
/*##############################################*/

char	*get_env_path(char **env, char *cmd);
void	ft_exit(char **argv);
int		cd(char *str);
int		env(void);
void	ft_pwd(void);
int		handle_cd_home(char **str);
int		change_to_path(char *path);
int		update_env(char *path, char *old_pwd);
char	*resolve_cd_path(char *str);
char	*check_and_create_new_path(DIR *dir, char *str, char *path);
void	set_path_to_parent(char *cwd, char **path);
void	env_add_back(t_env **env, t_env *new_node);
t_env	*env_init(char **envp);
t_env	*create_env_node(const char *entry);
int		env(void);
void	builtin_export(char **args, t_env **env);
int		is_valid_identifier(char *str);
void	env_set(t_env **env, char *key, char *value);
void	export_print(t_env *env);
void	builtin_unset(char **args, t_env **env);
void	env_remove(t_env **env, char *key);
int		is_valid_unset_key(char *str);

#endif
