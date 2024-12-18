# liboqs-test

### Paulo, Alberto

<img width="1578" alt="image" src="https://github.com/user-attachments/assets/6b50810b-0dbc-4b58-b4b8-f3de9bbfa8e2" />
<img width="986" alt="image" src="https://github.com/user-attachments/assets/8c614826-45ff-422e-9667-bb970fcad154" />

### Dificuldades encontradas:
1. Dificuldades para usar o compilador CL no MacOS. Tivemos que adaptar para o CLANG++
2. Os exemplos de comandos do repo são para windows, e não funcionam no mac (bash)
3. Eu uso um binário específico para o python, instalado com uma ferramenta não convencional. O CmakeList do programa tenta usar um python instalado com o Brew. Tive que alterar o cmakeList manualmente para usar o meu python.
4. Descobrir que o ultimo erro era sobre a libopenssl não estar sendo linkada.
