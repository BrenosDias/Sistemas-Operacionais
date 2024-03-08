#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void executar(char *comando) 
{
    int pid = fork();
    
    if (pid < 0) 
    {
        perror("Erro ao criar um novo processo");
        exit(1);
    } 
    else if (pid == 0) 
    {
        
        char *palavras[64];
        int quantPalavras = 0;
        
        // Separa o comando em tokens divididos por " " 
        char *token2 = strtok(comando, " ");
        
        while (token2 != NULL) 
        {
            palavras[quantPalavras++] = token2;
            token2 = strtok(NULL, " ");
        }
        
        palavras[quantPalavras] = NULL; // O último elemento da string tem que ser NULL
        
        // Executa o comando
        if (execvp(palavras[0], palavras) == -1) 
        {
            perror("Erro ao executar o comando");
            exit(1);
        }
    } 
    else 
    {
        int status;
        waitpid(pid, &status, 0);
        
    }
}


int main() {
    printf("Oi! Digite o seu comando:\n");
    char input[100];
    
    while (1) {
        printf("-> ");
        fgets(input, sizeof(input), stdin);
        
        // Retira a quebra de linha da string input
        input[strcspn(input, "\n")] = '\0';
        
        if (strcmp(input, "exit") == 0) 
        {
            break;
        } 
        else 
        {
            // Separa o input em tokens divididos por ";"
            char *token1 = strtok(input, ";");
            
            while (token1 != NULL) 
            {
                executar(token1);
                token1 = strtok(NULL, ";");
            }
        }
    }
    
    return 0;
}




