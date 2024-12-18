#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "oqs/oqs.h"

// Bloco 1: Função para escrever dados em um arquivo binário
void write_to_file(const char *filename, const uint8_t *data, size_t length)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }
    fwrite(data, 1, length, file);
    fclose(file);
}

// Bloco 2: Função para imprimir dados em formato hexadecimal com um rótulo
void print_hex(const char *label, const uint8_t *data, size_t length)
{
    printf("%s: ", label);
    for (size_t i = 0; i < length; i++)
    {
        printf("%02X", data[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("\n         ");
        }
    }
    printf("\n");
}

int main()
{
    printf("=== Alice: Geracao de chaves ===\n");

    // Utilizando o algoritmo ML-KEM com chaves de 1024 bits
    const char *kem_alg = OQS_KEM_alg_ml_kem_1024;
    printf("[INFO] Usando o algoritmo: %s\n", kem_alg);

    // Bloco 3: Inicializa o objeto KEM para o algoritmo especificado
    OQS_KEM *kem = OQS_KEM_new(kem_alg);
    if (kem == NULL)
    {
        fprintf(stderr, "Erro ao inicializar o KEM.\n");
        return EXIT_FAILURE;
    }

    // Bloco 4: Aloca memória para a chave pública e chave secreta
    uint8_t *public_key = (uint8_t *)malloc(kem->length_public_key);
    uint8_t *secret_key = (uint8_t *)malloc(kem->length_secret_key);

    // Bloco 5: Gera o par de chaves pública e secreta
    if (OQS_KEM_keypair(kem, public_key, secret_key) != OQS_SUCCESS)
    {
        fprintf(stderr, "Erro ao gerar par de chaves.\n");
        return EXIT_FAILURE;
    }

    // Bloco 6: Escreve as chaves geradas em arquivos binários
    write_to_file("public_key.bin", public_key, kem->length_public_key);
    write_to_file("secret_key.bin", secret_key, kem->length_secret_key);

    // Bloco 7: Imprime as chaves geradas em formato hexadecimal
    printf("[INFO] Chaves geradas:\n");
    print_hex("Chave pública", public_key, kem->length_public_key);
    print_hex("Chave secreta", secret_key, kem->length_secret_key);

    printf("[INFO] Arquivos gerados:\n");
    printf("  - public_key.bin\n");
    printf("  - secret_key.bin\n");

    // Bloco 8: Libera a memória alocada e finaliza o objeto KEM
    free(public_key);
    free(secret_key);
    OQS_KEM_free(kem);

    return EXIT_SUCCESS;
}