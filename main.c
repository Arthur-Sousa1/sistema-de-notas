#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 5

typedef struct {
    char nome[50];

    float port1;
    float port2;

    float mat1;
    float mat2;

    float edf1;
    float edf2;

    float mediaPortugues;
    float mediaMatematica;
    float mediaEdFisica;

    float mediaGeral;

} Aluno;

Aluno turma[MAX_ALUNOS];

int totalAlunos = 0;

void limparTela() {
    system("cls");
}

void voltarMenu() {

    int voltar;

    do {
        printf("\nDigite 0 para voltar: ");
        scanf("%d", &voltar);
    } while (voltar != 0);

    limparTela();
}

void cadastrarAluno() {
 
    limparTela();

    if (totalAlunos >= MAX_ALUNOS) {
        printf("\nLimite de alunos atingido!\n");
        return;
    }

    printf("\n=== CADASTRAR ALUNO ===\n");

    printf("Nome: ");
    scanf(" %49[^\n]", turma[totalAlunos].nome);

    printf("\nPORTUGUES\n");

    printf("Nota 1: ");
    scanf("%f", &turma[totalAlunos].port1);

    printf("Nota 2: ");
    scanf("%f", &turma[totalAlunos].port2);

    printf("\nMATEMATICA\n");

    printf("Nota 1: ");
    scanf("%f", &turma[totalAlunos].mat1);

    printf("Nota 2: ");
    scanf("%f", &turma[totalAlunos].mat2);

    printf("\nEDUCACAO FISICA\n");

    printf("Nota 1: ");
    scanf("%f", &turma[totalAlunos].edf1);

    printf("Nota 2: ");
    scanf("%f", &turma[totalAlunos].edf2);

    // Cálculo das médias

    turma[totalAlunos].mediaPortugues =
        (turma[totalAlunos].port1 +
         turma[totalAlunos].port2) / 2.0;

    turma[totalAlunos].mediaMatematica =
        (turma[totalAlunos].mat1 +
         turma[totalAlunos].mat2) / 2.0;

    turma[totalAlunos].mediaEdFisica =
        (turma[totalAlunos].edf1 +
         turma[totalAlunos].edf2) / 2.0;

    turma[totalAlunos].mediaGeral =
        (
            turma[totalAlunos].mediaPortugues +
            turma[totalAlunos].mediaMatematica +
            turma[totalAlunos].mediaEdFisica
        ) / 3.0;

    totalAlunos++;

    printf("\nAluno cadastrado com sucesso!\n");

    limparTela();
}


void mostrarNotas() {
 
    limparTela();

if (totalAlunos == 0) {
    printf("\nNenhum aluno cadastrado.\n");
    voltarMenu();
    return;
}

    printf("\n=== NOTAS FINAIS ===\n");

    for (int i = 0; i < totalAlunos; i++) {

      printf(
    "\nAluno: %s\n\n"

    "PORTUGUES\n"
    "Nota 1: %.2f\n"
    "Nota 2: %.2f\n"
    "Media: %.2f\n"
    "Situacao: %s\n\n"

    "MATEMATICA\n"
    "Nota 1: %.2f\n"
    "Nota 2: %.2f\n"
    "Media: %.2f\n"
    "Situacao: %s\n\n"

    "EDUCACAO FISICA\n"
    "Nota 1: %.2f\n"
    "Nota 2: %.2f\n"
    "Media: %.2f\n"
    "Situacao: %s\n",

    turma[i].nome,

    turma[i].port1,
    turma[i].port2,
    turma[i].mediaPortugues,
    turma[i].mediaPortugues >= 6 ? "APROVADO" : "REPROVADO",

    turma[i].mat1,
    turma[i].mat2,
    turma[i].mediaMatematica,
    turma[i].mediaMatematica >= 6 ? "APROVADO" : "REPROVADO",

    turma[i].edf1,
    turma[i].edf2,
    turma[i].mediaEdFisica,
    turma[i].mediaEdFisica >= 6 ? "APROVADO" : "REPROVADO"
);
   printf("=======================");
    }

     voltarMenu();
    limparTela();
   
}


void ranking() {

  limparTela();

   if (totalAlunos == 0) {
    printf("\nNenhum aluno cadastrado.\n");
    voltarMenu();
    return;
}

    Aluno copia[MAX_ALUNOS];

    for (int i = 0; i < totalAlunos; i++) {
        copia[i] = turma[i];
    }

    for (int i = 0; i < totalAlunos - 1; i++) {

        for (int j = 0; j < totalAlunos - 1 - i; j++) {

           if (copia[j].mediaGeral < copia[j + 1].mediaGeral) {

                Aluno temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\n=== RANKING ===\n");

    for (int i = 0; i < totalAlunos; i++) {

 
       printf("%do lugar - %s (%.2f)\n",
       i + 1,
       copia[i].nome,
       copia[i].mediaGeral); 
  }
for (int i = 0; i < totalAlunos; i++) {
    copia[i] = turma[i];
}

for (int i = 0; i < totalAlunos - 1; i++) {

    for (int j = 0; j < totalAlunos - 1 - i; j++) {

        if (copia[j].mediaPortugues <
            copia[j + 1].mediaPortugues) {

            Aluno temp = copia[j];
            copia[j] = copia[j + 1];
            copia[j + 1] = temp;
        }
    }
}

printf("\n=== RANKING PORTUGUES ===\n");

for (int i = 0; i < totalAlunos; i++) {

    printf(
        "%do lugar - %s (%.2f)\n",
        i + 1,
        copia[i].nome,
        copia[i].mediaPortugues
    );
}
for (int i = 0; i < totalAlunos; i++) {
    copia[i] = turma[i];
}

for (int i = 0; i < totalAlunos - 1; i++) {

    for (int j = 0; j < totalAlunos - 1 - i; j++) {

        if (copia[j].mediaMatematica <
            copia[j + 1].mediaMatematica) {

            Aluno temp = copia[j];
            copia[j] = copia[j + 1];
            copia[j + 1] = temp;
        }
    }
}

printf("\n=== RANKING MATEMATICA ===\n");

for (int i = 0; i < totalAlunos; i++) {

    printf(
        "%do lugar - %s (%.2f)\n",
        i + 1,
        copia[i].nome,
        copia[i].mediaMatematica
    );
}
for (int i = 0; i < totalAlunos; i++) {
    copia[i] = turma[i];
}

for (int i = 0; i < totalAlunos - 1; i++) {

    for (int j = 0; j < totalAlunos - 1 - i; j++) {

        if (copia[j].mediaEdFisica <
            copia[j + 1].mediaEdFisica) {

            Aluno temp = copia[j];
            copia[j] = copia[j + 1];
            copia[j + 1] = temp;
        }
    }
}

printf("\n=== RANKING EDUCACAO FISICA ===\n");

for (int i = 0; i < totalAlunos; i++) {

    printf(
        "%do lugar - %s (%.2f)\n",
        i + 1,
        copia[i].nome,
        copia[i].mediaEdFisica
    );
}
    voltarMenu();
    limparTela();
 }

void aprovadosReprovados() {

    limparTela();

    if (totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        voltarMenu();
        return;
    }

    printf("\n=== APROVADOS E REPROVADOS ===\n");

    for (int i = 0; i < totalAlunos; i++) {

        printf("\nAluno: %s\n\n", turma[i].nome);

        printf(
            "Portugues: %.2f - %s\n",
            turma[i].mediaPortugues,
            turma[i].mediaPortugues >= 6 ? "APROVADO" : "REPROVADO"
        );

        printf(
            "Matematica: %.2f - %s\n",
            turma[i].mediaMatematica,
            turma[i].mediaMatematica >= 6 ? "APROVADO" : "REPROVADO"
        );

        printf(
            "Educacao Fisica: %.2f - %s\n",
            turma[i].mediaEdFisica,
            turma[i].mediaEdFisica >= 6 ? "APROVADO" : "REPROVADO"
        );

        printf("\n=========================\n");
    }

    voltarMenu();
}
void menu() {

    int opcao;

    do {

        printf("\n========================\n");
        printf("NOTAS DE ALUNOS\n");
        printf("========================\n");

        printf("1 - Cadastrar aluno\n");
        printf("2 - Ver notas finais\n");
        printf("3 - Ranking\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrarAluno();
                break;

            case 2:
                mostrarNotas();
                break;

            case 3:
                ranking();
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);
}

int main() {

    menu();
    
    return 0;
}