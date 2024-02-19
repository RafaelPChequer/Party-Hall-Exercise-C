#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[20];
    char dataNascimento[20];
} Cliente;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
} Fornecedor;

typedef struct {
    int codigo;
    int quantidadeConvidados;
    char data[20];
    char diaSemana[20];
    char horarioInicio[10];
    char horarioTermino[10];
    char tema[50];
    int codigoCliente;
    int codigoFornecedor;
} Festa;

typedef struct {
    int numeroContrato;
    float valorTotal;
    float desconto;
    float valorFinal;
    char formaPagamento[20];
    char status[20];
    int codigoFesta;
} Contrato;

// Função para cadastrar um cliente
void cadastrarCliente() {
    Cliente cliente;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &cliente.codigo);

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", cliente.nome);

    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]s", cliente.endereco);

    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]s", cliente.telefone);

    printf("Digite a data de nascimento do cliente: ");
    scanf(" %[^\n]s", cliente.dataNascimento);

    FILE *arquivoClientes;
    arquivoClientes = fopen("clientes.txt", "a");
    if (arquivoClientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fwrite(&cliente, sizeof(Cliente), 1, arquivoClientes);
    fclose(arquivoClientes);

    printf("Cliente cadastrado com sucesso.\n");
    printf("\n");
}

// Função para cadastrar um fornecedor
void cadastrarFornecedor() {
    Fornecedor fornecedor;

    printf("Digite o codigo do fornecedor: ");
    scanf("%d", &fornecedor.codigo);

    printf("Digite o nome do buffet: ");
    scanf(" %[^\n]s", fornecedor.nome);

    printf("Digite o telefone do fornecedor: ");
    scanf(" %[^\n]s", fornecedor.telefone);

    FILE *arquivoFornecedores;
    arquivoFornecedores = fopen("fornecedores.txt", "a");
    if (arquivoFornecedores == NULL) {
        printf("Erro ao abrir o arquivo de fornecedores.\n");
        return;
    }

    fwrite(&fornecedor, sizeof(Fornecedor), 1, arquivoFornecedores);
    fclose(arquivoFornecedores);

    printf("Fornecedor cadastrado com sucesso.\n");
    printf("\n");
}

// Função para cadastrar uma festa
void cadastrarFesta() {
    Festa festa;

    printf("Digite o codigo da festa: ");
    scanf("%d", &festa.codigo);

    printf("Digite a quantidade de convidados: ");
    scanf("%d", &festa.quantidadeConvidados);

    printf("Digite a data da festa: ");
    scanf(" %[^\n]s", festa.data);

    printf("Digite o dia da semana da festa: ");
    scanf(" %[^\n]s", festa.diaSemana);

    printf("Digite o horario de início da festa: ");
    scanf(" %[^\n]s", festa.horarioInicio);

    printf("Digite o horario de término da festa: ");
    scanf(" %[^\n]s", festa.horarioTermino);

    printf("Digite o tema da festa: ");
    scanf(" %[^\n]s", festa.tema);

    printf("Digite o codigo do cliente: ");
    scanf("%d", &festa.codigoCliente);

    printf("Digite o codigo do fornecedor: ");
    scanf("%d", &festa.codigoFornecedor);

    FILE *arquivoFestas;
    arquivoFestas = fopen("festas.txt", "a");
    if (arquivoFestas == NULL) {
        printf("Erro ao abrir o arquivo de festas.\n");
        return;
    }

    fwrite(&festa, sizeof(Festa), 1, arquivoFestas);
    fclose(arquivoFestas);

    printf("Festa cadastrada com sucesso.\n");
    printf("\n");
}

// Função para calcular o valor total e final do contrato
void calcularValorContrato() {
    int codigoFesta;

    printf("Digite o codigo da festa: ");
    scanf("%d", &codigoFesta);

    FILE *arquivoFestas;
    arquivoFestas = fopen("festas.txt", "r+");
    if (arquivoFestas == NULL) {
        printf("Erro ao abrir o arquivo de festas.\n");
        return;
    }

    Festa festa;
    int encontrado = 0;
    while (fread(&festa, sizeof(Festa), 1, arquivoFestas) == 1) {
        if (festa.codigo == codigoFesta) {
            Contrato contrato;
            contrato.numeroContrato = rand() % 1000 + 1; // Gera um número de contrato aleatório entre 1 e 1000

            // Cálculo do valor total baseado na quantidade de convidados e dia da semana
            if (festa.quantidadeConvidados <= 30) {
                if (strcmp(festa.diaSemana, "Sexta") == 0 || strcmp(festa.diaSemana, "Sabado") == 0 || strcmp(festa.diaSemana, "Domingo") == 0) {
                    contrato.valorTotal = 2099.00;
                } else {
                    contrato.valorTotal = 1899.00;
                }
            } else if (festa.quantidadeConvidados <= 50) {
                if (strcmp(festa.diaSemana, "Sexta") == 0 || strcmp(festa.diaSemana, "Sabado") == 0 || strcmp(festa.diaSemana, "Domingo") == 0) {
                    contrato.valorTotal = 2299.00;
                } else {
                    contrato.valorTotal = 2199.00;
                }
            } else if (festa.quantidadeConvidados <= 80) {
                if (strcmp(festa.diaSemana, "Sexta") == 0 || strcmp(festa.diaSemana, "Sabado") == 0 || strcmp(festa.diaSemana, "Domingo") == 0) {
                    contrato.valorTotal = 3499.00;
                } else {
                    contrato.valorTotal = 3199.00;
                }
            } else if (festa.quantidadeConvidados <= 100) {
                if (strcmp(festa.diaSemana, "Sexta") == 0 || strcmp(festa.diaSemana, "Sabado") == 0 || strcmp(festa.diaSemana, "Domingo") == 0) {
                    contrato.valorTotal = 3999.00;
                } else {
                    contrato.valorTotal = 3799.00;
                }
            }

            // Cálculo do desconto baseado na forma de pagamento
            printf("Selecione a forma de pagamento:\n");
            printf("1 - A vista\n");
            printf("2 - Duas vezes\n");
            printf("3 - Tres vezes\n");
            printf("4 - Quatro ou mais vezes\n");
            int formaPagamento;
            scanf("%d", &formaPagamento);

            switch (formaPagamento) {
                case 1:
                    strcpy(contrato.formaPagamento, "A vista");
                    contrato.desconto = contrato.valorTotal * 0.1;
                    break;
                case 2:
                    strcpy(contrato.formaPagamento, "Duas vezes");
                    contrato.desconto = contrato.valorTotal * 0.05;
                    break;
                case 3:
                    strcpy(contrato.formaPagamento, "Tres vezes");
                    contrato.desconto = contrato.valorTotal * 0.02;
                    break;
                case 4:
                    strcpy(contrato.formaPagamento, "Quatro ou mais vezes");
                    contrato.desconto = 0.0;
                    break;
                default:
                    printf("Opção invalida.\n");
                    fclose(arquivoFestas);
                    return;
            }

            contrato.valorFinal = contrato.valorTotal - contrato.desconto;
            strcpy(contrato.status, "a pagar");
            contrato.codigoFesta = codigoFesta;

            fseek(arquivoFestas, -sizeof(Festa), SEEK_CUR);
            fwrite(&festa, sizeof(Festa), 1, arquivoFestas);

            FILE *arquivoContratos;
            arquivoContratos = fopen("contratos.txt", "a");
            if (arquivoContratos == NULL) {
                printf("Erro ao abrir o arquivo de contratos.\n");
                fclose(arquivoFestas);
                return;
            }

            fwrite(&contrato, sizeof(Contrato), 1, arquivoContratos);
            fclose(arquivoContratos);

            printf("Valor total do contrato: R$ %.2f\n", contrato.valorTotal);
            printf("Desconto aplicado: R$ %.2f\n", contrato.desconto);
            printf("Valor final do contrato: R$ %.2f\n", contrato.valorFinal);
            printf("Forma de pagamento: %s\n", contrato.formaPagamento);
            printf("Status do contrato: %s\n", contrato.status);
            printf("Contrato gerado com sucesso.\n");

            encontrado = 1;
            break;
        }
    }

    fclose(arquivoFestas);

    if (!encontrado) {
        printf("Festa nao encontrada.\n");
    }

    printf("\n");
}

// Função para atualizar o status do contrato
void atualizarStatusContrato() {
    int numeroContrato;
    char novoStatus[20];

    printf("Digite o numero do contrato: ");
    scanf("%d", &numeroContrato);

    printf("Digite o novo status (pago ou cancelado): ");
    scanf(" %[^\n]s", novoStatus);

    FILE *arquivoContratos;
    arquivoContratos = fopen("contratos.txt", "r+");
    if (arquivoContratos == NULL) {
        printf("Erro ao abrir o arquivo de contratos.\n");
        return;
    }

    Contrato contrato;
    int encontrado = 0;
    while (fread(&contrato, sizeof(Contrato), 1, arquivoContratos) == 1) {
        if (contrato.numeroContrato == numeroContrato) {
            strcpy(contrato.status, novoStatus);

            fseek(arquivoContratos, -sizeof(Contrato), SEEK_CUR);
            fwrite(&contrato, sizeof(Contrato), 1, arquivoContratos);

            printf("Status do contrato atualizado com sucesso.\n");

            encontrado = 1;
            break;
        }
    }

    fclose(arquivoContratos);

    if (!encontrado) {
        printf("Contrato nao encontrado.\n");
    }

    printf("\n");
}

// Função para pesquisar informações do cliente pelo código
void pesquisarClientePorCodigo() {
    int codigoCliente;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    FILE *arquivoClientes;
    arquivoClientes = fopen("clientes.txt", "r");
    if (arquivoClientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    Cliente cliente;
    int encontrado = 0;
    while (fread(&cliente, sizeof(Cliente), 1, arquivoClientes) == 1) {
        if (cliente.codigo == codigoCliente) {
            printf("Codigo do cliente: %d\n", cliente.codigo);
            printf("Nome: %s\n", cliente.nome);
            printf("Endereco: %s\n", cliente.endereco);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Data de Nascimento: %s\n", cliente.dataNascimento);

            encontrado = 1;
            break;
        }
    }

    fclose(arquivoClientes);

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    printf("\n");
}

// Função para pesquisar informações de fornecedores pelo código
void pesquisarFornecedorPorCodigo() {
    int codigoFornecedor;

    printf("Digite o codigo do fornecedor: ");
    scanf("%d", &codigoFornecedor);

    FILE *arquivoFornecedores;
    arquivoFornecedores = fopen("fornecedores.txt", "r");
    if (arquivoFornecedores == NULL) {
        printf("Erro ao abrir o arquivo de fornecedores.\n");
        return;
    }

    Fornecedor fornecedor;
    int encontrado = 0;
    while (fread(&fornecedor, sizeof(Fornecedor), 1, arquivoFornecedores) == 1) {
        if (fornecedor.codigo == codigoFornecedor) {
            printf("Codigo do fornecedor: %d\n", fornecedor.codigo);
            printf("Nome do buffet: %s\n", fornecedor.nome);
            printf("Telefone: %s\n", fornecedor.telefone);

            encontrado = 1;
            break;
        }
    }

    fclose(arquivoFornecedores);

    if (!encontrado) {
        printf("Fornecedor nao encontrado.\n");
    }

    printf("\n");
}

// Função para exibir todas as festas de um determinado cliente
void exibirFestasPorCliente() {
    int codigoCliente;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    FILE *arquivoFestas;
    arquivoFestas = fopen("festas.txt", "r");
    if (arquivoFestas == NULL) {
        printf("Erro ao abrir o arquivo de festas.\n");
        return;
    }

    Festa festa;
    int encontrado = 0;
    while (fread(&festa, sizeof(Festa), 1, arquivoFestas) == 1) {
        if (festa.codigoCliente == codigoCliente) {
            printf("Codigo da festa: %d\n", festa.codigo);
            printf("Quantidade de convidados: %d\n", festa.quantidadeConvidados);
            printf("Data: %s\n", festa.data);
            printf("Dia da semana: %s\n", festa.diaSemana);
            printf("Horario de inicio: %s\n", festa.horarioInicio);
            printf("Horario de termino: %s\n", festa.horarioTermino);
            printf("Tema: %s\n", festa.tema);
            printf("Codigo do cliente: %d\n", festa.codigoCliente);
            printf("Codigo do fornecedor: %d\n", festa.codigoFornecedor);
            printf("\n");

            encontrado = 1;
        }
    }

    fclose(arquivoFestas);

    if (!encontrado) {
        printf("Nenhuma festa encontrada para o cliente.\n");
    }

    printf("\n");
}

// Função principal
int main() {
    int opcao;

    do {
        printf("Selecione uma opcao:\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar fornecedor\n");
        printf("3 - Cadastrar festa\n");
        printf("4 - Calcular valor do contrato\n");
        printf("5 - Atualizar status do contrato\n");
        printf("6 - Pesquisar cliente por codigo\n");
        printf("7 - Pesquisar fornecedor por codigo\n");
        printf("8 - Exibir festas por cliente\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFornecedor();
                break;
            case 3:
                cadastrarFesta();
                break;
            case 4:
                calcularValorContrato();
                break;
            case 5:
                atualizarStatusContrato();
                break;
            case 6:
                pesquisarClientePorCodigo();
                break;
            case 7:
                pesquisarFornecedorPorCodigo();
                break;
            case 8:
                exibirFestasPorCliente();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}