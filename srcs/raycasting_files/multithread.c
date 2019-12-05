#include "raycast.h"

#define MAX_THREAD 50

void    multi_thread(t_env *e)
{
    int         i;
    t_env       env[99];
    pthread_t   thread[99];
// printf("enter multi_thread\n");
    i = 0;
    while(i < MAX_THREAD)
    {
        ft_memcpy((void*)&env[i], (void*) e, sizeof(t_env));
        env[i].y_min = i * e->width / MAX_THREAD;
        env[i].y_max = (i + 1) * e->width / MAX_THREAD;
		//env[i].thread = i;
        // printf("ymin:%i\n",env[i].y_min);
        // printf("ymax:%i\n",env[i].y_max);
        pthread_create(&thread[i], NULL, (void*)raycast, &env[i]);
        i++;
    }
    while (i--)
        pthread_join(thread[i], NULL);
}
