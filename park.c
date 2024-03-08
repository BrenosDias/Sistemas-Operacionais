#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N_CARROS 50
#define N_ESPERA 10
#define N_VAGAS 10

sem_t lock_estacionamento;
sem_t sem_espera;
sem_t flanelinha;
sem_t vaga;


void * f_flanelinha(void *v);


void * f_cliente(void* v);


int main()
{
    pthread_t thr_clientes[N_CARROS], thr_flanelinha;
    int i, id[N_CARROS];

    sem_init(&lock_estacionamento, 0, N_VAGAS);
    sem_init(&sem_espera, 0, N_ESPERA);
    sem_init(&flanelinha, 0, 0);
    sem_init(&vaga, 0, 0);

    for (i = 0; i < N_CARROS; i++)
    {
        id[i] = i;
        pthread_create(&thr_clientes[i], NULL, f_cliente, (void *)&id[i]);
    }

    pthread_create(&thr_flanelinha, NULL, f_flanelinha, NULL);

    for (i = 0; i < N_CARROS; i++)
    {
        pthread_join(thr_clientes[i], NULL);
    }

    return 0;
}

void * f_flanelinha(void *v)
{
    while (1)
    {
        sem_wait(&flanelinha);

        sleep(1);
        printf("Carro saiu do estacionamento\n");

        sem_post(&vaga);
    }
    pthread_exit(0);
}

void * f_cliente(void* v)
{
    int id = *(int*)v;
    sleep(id % 7);
    if (sem_trywait(&sem_espera) == 0)
    {
        printf("Carro %d esta esperando \n", id);
        sem_wait(&lock_estacionamento);
        sem_post(&sem_espera);
        printf("Carro %d entrou no estacionamento \n", id);
        sem_post(&flanelinha);
        sem_wait(&vaga);
        sem_post(&lock_estacionamento);
    }
    else
    {
        printf("Sem vaga\n");
    }

    pthread_exit(0);
}


