#include "get_next_line.h"

char	*get_new_line(t_list *list)
{
	char	*result;

	int i, j = 0;
	if (list == NULL)
		return (NULL);
	result = (char *)malloc(len_str_list(list) + 1); // Add
	if (!result)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			result[j] = list->buf[i];
			if (list->buf[i] == '\n')
			{
				result[++j] = '\0'; // Null terminate the result
				return (result);    // Return when newline is found
			}
			i++;
			j++;
		}
		list = list->next;
	}
	result[j] = '\0'; // Null terminate if no newline is found
	return (result);
}

void	add_buf(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		return ;
	}
	new_node->buf = buf;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	else
	{
		temp = *list;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
	{
		return (0);
	}
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		char_read;

	while (!found_newline(*list))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		// printf("bufs : %s\n", buf);
		add_buf(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &result, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	result = get_new_line(list);
	polish_list(&list);
	return (result);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*result;

// 	fd = open("sample.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	write(fd, "Hello\nWorld", 11);
// 	lseek(fd, 0, SEEK_SET);

// 	// while(get_next_line(fd)!=NULL)
// 	// {
// 	// 	result = get_next_line(fd);
// 	// 	printf("%s",result);
// 	// }
// 	result = get_next_line(fd);
// 	printf("%s\n",result);
// 	result = get_next_line(fd);
// 	printf("%s",result);

// 	close(fd);
// 	// printf("%s", result);
// 	return (0);
// }
// int	main(void)
// {
// 	int		fd;
// 	char	*result;

// 	fd = open("sample.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	write(fd, "Hello\nWorld", 11);
// 	lseek(fd, 0, SEEK_SET);
// 	while ((result = get_next_line(fd)) != NULL)
// 	{
// 		printf("buff %s;\n", result);
// 		free(result); // Free the result after printing
// 	}
// 	close(fd);
// 	return (0);
// }
