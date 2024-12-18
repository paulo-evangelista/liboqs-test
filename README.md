# liboqs-test

### Paulo, Alberto

<img width="1578" alt="image" src="https://github.com/user-attachments/assets/6b50810b-0dbc-4b58-b4b8-f3de9bbfa8e2" />
<img width="986" alt="image" src="https://github.com/user-attachments/assets/8c614826-45ff-422e-9667-bb970fcad154" />
<img width="934" alt="image" src="https://github.com/user-attachments/assets/ca5d7a84-182c-4832-aa35-37962402cb96" />

Prova que o shared secret entre alice e bob realmente são iguais:
<img width="671" alt="image" src="https://github.com/user-attachments/assets/25f857e2-6f47-4d72-b067-d6baec2363fd" />

gerando AES:
<img width="965" alt="image" src="https://github.com/user-attachments/assets/7edbe3d7-3dbb-426e-9429-321daedf46dc" />


### Ambiente
MacOS (arm64) com clang++ 16.0.0

### Dificuldades encontradas:
1. Dificuldades para usar o compilador CL no MacOS. Tivemos que adaptar para o CLANG++
2. Os exemplos de comandos do repo são para windows, e não funcionam no mac (bash)
3. Eu uso um binário específico para o python, instalado com uma ferramenta não convencional. O CmakeList do programa tenta usar um python instalado com o Brew. Tive que alterar o cmakeList manualmente para usar o meu python.
4. Descobrir que o ultimo erro era sobre a libopenssl não estar sendo linkada.
