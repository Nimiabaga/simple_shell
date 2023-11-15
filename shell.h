#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>

#define MAX_LINE_LENGTH 1024



void handle_script_mode(int argc, char argv[]);
void run_command(charcommand, char arguments);

char find_full_path(const charcommand);
int startsWith(const char str, const charprefix);

void process_cmdline(char input_line);
int my_builtins(char cmd);
int execute_setenv(const char env_variable, const chardata);
int execute_unsetenv(const char *env_variable);
void execute_env(char args);
char my_getline();
void my_cd(char **args);
void tokenize_input(chardata_input);
extern char environ;


int user_input(char input, size_t data);



void handle_script_mode(int argc, charargv[]);
void my_exit(char args, int *status);
void exit_shell();
void my_cd(char args);

void run_command(char command, char **arguments);

charfind_full_path(const char command);
int startsWith(const charstr, const char prefix);



#endif / SHELL_H */

