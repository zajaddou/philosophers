/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:26:31 by zajaddou          #+#    #+#             */
/*   Updated: 2025/07/23 16:38:17 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
int bj = 0;
pthread_mutex_t locky    =  PTHREAD_MUTEX_INITIALIZER;

void *task(void *arg)
{
    (void)arg;
    // int i = 0;
    // while(i < 100000)
    // { i++;
    //     pthread_mutex_lock(&locky);
    //     bj++;
    //     pthread_mutex_unlock(&locky);
    // }
    printf("hello\n");
    return (NULL);
}
int main()
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1,NULL, task,NULL);
    // pthread_create(&t2,NULL, task,NULL);
    pthread_detach(t1);
    // sleep(1);
    // printf("the value of j is :%d\n", bj);
    return (0);
}
