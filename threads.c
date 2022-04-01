#include <pthread.h>
#include <stdio.h>

void	*test1(void *data)
{
	printf("hello\n");
	return (0);
}

void	*test2(void *data)
{
	int	*num = data;

	while (*num < 100000)
		(*num)++;
	return (0);
}

// int	main(void)
// {
// 	pthread_t	id;
// 	void		*ret;
// 	pthread_create(&id, 0, test, 0);
// 	// join or detach
// 	// в ret запишется значение, возвращаемое test
// 	pthread_join(id, &ret);
// 	return (0);
// }

int	main(void)
{
	int			tmp = 0;
	pthread_t	id;
	void		*ret;
	pthread_create(&id, 0, test2, &tmp);
	while (tmp < 100000)
	{
		printf("%d\n", tmp);
	}
	// join or detach
	// в ret запишется значение, возвращаемое test
	pthread_join(id, &ret);
	return (0);
}