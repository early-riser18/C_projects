char	*get_env_val(char *env_key);
char	*resolve_filepath(char *short_path);
char	**parse_args(char *args);
int		*create_child(int fd_in, int fd_out, char *cmd_str, char **environ);
int		validate_input(int argc, char *argv[]);