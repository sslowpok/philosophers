#include <pthread.h>
#include <stdio.h>

// typedef pthread_mutex_t t_mutex;

// typedef struct s_data
// {
// 	t_mutex *p_mutex;
// 	int		*num;
// }		t_data;

// void	*test1(void *data)
// {
// 	printf("hello\n");
// 	return (0);
// }



// int	main(void)
// {
// 	t_mutex	mutex;
// 	int			tmp = 0;
// 	pthread_t	id;
// 	void		*ret;
// 	pthread_create(&id, 0, test2, &tmp);
// 	while (tmp < 100000)
// 	{
// 		printf("%d\n", tmp);
// 	}
// 	// join or detach
// 	// в ret запишется значение, возвращаемое test
// 	// pthread_mutex_init(*mutex, 0, ...)
// 	// pthread_mutex_lock(*mutex)
// 	// pthread_mutex_unlock(*mutex)

// 	// pthread_join(id, &ret);
// 	return (0);
// }

// void	*ft_run(void *data)
// {
// 	int	*num = data;

// }

// void	*test2(void *data, pthread_mutex_t *mutex)
// {
// 	int	*num = data;

// 	pthread_mutex_lock(&mutex);
// 	while (*num < 100000)
// 		(*num)++;
// 	pthread_mutex_unlock(&mutex);
// 	return (0);
// }

// int	main()
// {
// 	t_mutex		mutex;
// 	int			tmp;
// 	pthread_t	id;
// 	t_data		data;

// 	pthread_mutex_init(&mutex, 0);
// 	pthread_create(&id, 0, ft_run, &tmp);

// 	return (0);
// }


void	*func(void *args)
{
	printf("Hello world\n");
	return ((void *)0);
}

int	main(void)
{
	pthread_t	thread;
	int			id;

	id = pthread_create(&thread, NULL, func, NULL);
	if (id != 0)
		printf("thread error\n");
	id = pthread_join(thread, 0);
	printf("Hello from main\n");
	
	return (0);


}