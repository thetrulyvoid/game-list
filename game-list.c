#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sleep_ms(int milliseconds)
{
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

int main(void)
{

    void clear_screen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void open_editor()
    {
#ifdef _WIN32
        system("notepad log.txt");
#else
        system("nano log.txt");
#endif
    }

    clear_screen();

    int escolha;

    char jogos[1000];

    int quantidadeJogos;

    FILE *file;

    printf("Welcome to your Game List, that program contains your personal game list to play in the future. Please, select a option\nType [1] to Create a New List\nType [2] to View your List\nType [3] to Edit a List\n\n");

    scanf("%d", &escolha);
    while (escolha > 3 || escolha < 1)
    {
        clear_screen();
        printf("Please, type a valid number:\n\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            scanf("%d", &escolha);
    }
    if (escolha == 1)
    {

        clear_screen();
        printf("Great, let's Create a New List!\n\n");
        sleep_ms(2000);

        clear_screen();

        file = fopen("log.txt", "w");
        fprintf(file, "Your games on the list now are:\n\n");

        printf("Please, type below how many games do you want to add to your list:\n\n");

        scanf("%d", &quantidadeJogos);
        getchar();

        clear_screen();

        printf("Okay, %d games! Write them below:\n\n", quantidadeJogos);

        for (int i = 0; quantidadeJogos > i; i++)
        {

            fgets(jogos, 1000, stdin);
            fprintf(file, "%s", jogos);
            memset(jogos, 0, sizeof(jogos));
        }

        clear_screen();

        printf("Great, we now have the games on the list! Do you want to see them?\nType [1] to yes\nType [2] to no\n\n");

        int escolha2;

        scanf("%d", &escolha2);

        while (escolha2 > 2 || escolha2 < 1)
        {
            clear_screen();
            printf("Please, type a valid number:\n\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                scanf("%d", &escolha2);
        }

        fclose(file);

        if (escolha2 == 1)
        {

            open_editor();
            return 0;
        }
    }

    else if (escolha == 2)
    {

        file = fopen("log.txt", "r");
        clear_screen();
        if (file == NULL)
        {

            printf("You don't have any list, create one to see it!\n\n");
            return 0;
        }

        else
        {
            printf("Okay, your list will apper soon!\n\n");

            sleep_ms(2000);
            clear_screen();

            open_editor();
            return 0;
        }
    }

    else if (escolha == 3)
    {

        file = fopen("log.txt", "a");

        clear_screen();

        if (file != NULL)
        {
            printf("Okay, type below how many games you want to add to your list:\n\n");

            scanf("%d", &quantidadeJogos);
            getchar();

            clear_screen();

            printf("Okay, %d games! Write them below:\n\n", quantidadeJogos);

            for (int i = 0; quantidadeJogos > i; i++)
            {

                fgets(jogos, 1000, stdin);
                fprintf(file, "%s", jogos);
                memset(jogos, 0, sizeof(jogos));
            }

            clear_screen();

            printf("Great, we now have the games on the list! Do you want to see them?\nType [1] to yes\nType [2] to no\n\n");

            int escolha2;

            scanf("%d", &escolha2);

            while (escolha2 > 2 || escolha2 < 1)
            {
                clear_screen();
                printf("Please, type a valid number:\n\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    scanf("%d", &escolha2);
            }

            fclose(file);

            if (escolha2 == 1)
            {

                open_editor();
                clear_screen();
                return 0;
            }
        }

        else
        {
            printf("You don't have any list, create one to add games on it!\n\n");
            return 0;
        }
    }
}