#include "main.h"

int main(int argc, char **argv)
{
    pthread_t pid_analyse_nitrate;
    pthread_t pid_network;

    printf("%d\n", getNumberOfAnalyse("nitrate"));

    pthread_create (&pid_analyse_nitrate, NULL, analyseNitrate, NULL);
    pthread_create (&pid_network, NULL, network, NULL);

    // Waiting the end of the network thread
    pthread_join(pid_network, NULL);
    printf("\nOK !\n");

    // cancel other threads
    pthread_cancel(pid_analyse_temp);
    pthread_cancel(pid_analyse_nitrate);

    return EXIT_SUCCESS;
}
