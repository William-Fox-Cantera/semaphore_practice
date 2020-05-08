/**
# CISC-361 Operating Systems homework assignment #3
# By: William Cantera
# Email: wcantera@udel.edu
# Student ID: 702464888
#
# NOTE: I worked alone
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s1, s2; // Four threads, two semaphores 

void *worker1(void *arg) {
  sem_wait(&s1);
  printf("I am worker 1\n");
  sem_post(&s2);
  pthread_exit(NULL);
}

void *worker2(void *arg) {
  printf("I am worker 2\n");
  sem_post(&s1);
  sem_post(&s1);
  pthread_exit(NULL);
}

void *worker3(void *arg) {
  sem_wait(&s2);
  sem_wait(&s2);
  printf("I am worker 3\n");
  pthread_exit(NULL);
}

void *worker4(void *arg) {
  sem_wait(&s1);
  printf("I am worker 4\n");
  sem_post(&s2);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t p1, p2, p3, p4;
  sem_init(&s1, 0, 0);
  sem_init(&s2, 0, 0);

  pthread_create(&p3, NULL, worker3, NULL);
  pthread_create(&p4, NULL, worker4, NULL);
  pthread_create(&p2, NULL, worker2, NULL);
  pthread_create(&p1, NULL, worker1, NULL); 

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  pthread_join(p3, NULL);
  pthread_join(p4, NULL);
  printf("done.......\n");
  return 0;
}