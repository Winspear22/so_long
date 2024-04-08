#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen_2(const char *s);
char	*ft_strdup_2(const char *s);
void	*ft_memmove_2(char *save, char *buf, int n);
char	*ft_strjoin_2(char *save, char *buf);
char	*ft_strchr_2(char *save, int c);

#endif