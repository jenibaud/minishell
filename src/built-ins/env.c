#include "minishell.h"

extern char **environ;

int	env(void)
{
	char	**env;
	env = environ;
	while (*env != NULL)
	{
        printf("%s\n", *env);
		env++;
    }
    return 0;
}

t_env *create_env_node(const char *entry) {
    int i = 0;
    while (entry[i] && entry[i] != '=')
        i++;

    t_env *node = malloc(sizeof(t_env));
    if (!node)
        return NULL;

    node->key = ft_substr(entry, 0, i);
    if (entry[i] == '=')
        node->value = ft_strdup(entry + i + 1);
    else
        node->value = NULL;
    node->next = NULL;

    return node;
}

void env_add_back(t_env **env, t_env *new_node) {
    if (!*env) {
        *env = new_node;
        return;
    }

    t_env *temp = *env;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

t_env *env_init(char **envp) {
    t_env *env_list = NULL;

    for (int i = 0; envp[i]; i++) {
        t_env *node = create_env_node(envp[i]);
        if (node)
            env_add_back(&env_list, node);
    }

    return env_list;
}
