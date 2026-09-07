# 🎬 Sistema de Gerenciamento de Cinema (C++)

Sistema em C++ para cadastro de filmes, listagem, cálculo de 
arrecadação e identificação do filme com maior faturamento, 
rodando via console (terminal).

## 📋 Funcionalidades

- Cadastro de novos filmes (título, gênero, duração, preço do 
  ingresso e ingressos vendidos)
- Listagem de todos os filmes cadastrados
- Identificação automática do filme com maior arrecadação
- Cálculo da arrecadação total de todos os filmes (utilizando 
  sobrecarga de funções)

## 🛠️ Tecnologias Utilizadas

- C++ 
- Biblioteca `<iostream>` para entrada/saída
- Struct (`Filme`) para organização dos dados
- Sobrecarga de funções (`calcularArrecadacao`)

## 💻 Como Compilar e Executar

### Pré-requisitos
- Compilador g++ instalado
- Compilador `g++` configurado na variável de ambiente PATH
- VS Code (opcional, mas o projeto já vem configurado para ele)

Verifique se está tudo pronto com:

```bash
g++ --version
```

Se a versão do compilador for exibida, o ambiente está pronto 
para compilar o projeto.

### Compilando pelo terminal
\`\`\`bash
g++ main.cpp -o cinema.exe
./cinema.exe
\`\`\`

### Compilando pelo VS Code
1. Abra a pasta do projeto no VS Code
2. Pressione F5 (as configurações de build já estão prontas em `.vscode/`)

## 📖 Como Usar

Ao rodar o programa, um menu será exibido:

\`\`\`
================ CINEMA MENU ================
 [1] Cadastrar novo filme
 [2] Listar todos os filmes
 [3] Mostrar filme com maior arrecadação
 [4] Mostrar arrecadação total (sobrecarga)
---------------------------------------------
 [x] Pressione qualquer outra tecla para sair
=============================================
\`\`\`

Basta digitar o número da opção desejada e seguir as instruções.

## 📌 Estrutura de Dados

O sistema utiliza uma struct para representar cada filme:

\`\`\`cpp
typedef struct {
    string titulo;
    string genero;
    int duracaoMin;
    float precoIngresso;
    int ingressosVendidos;
} Filme;
\`\`\`

## 🚧 Melhorias Futuras

- Persistência de dados em arquivo (atualmente os dados são 
  perdidos ao fechar o programa)
- Validação de entradas do usuário
- Edição e remoção de filmes cadastrados
- Criação de uma interface 

## 📄 Licença

Este projeto está sob a licença MIT — veja o arquivo [LICENSE](LICENSE) 
para mais detalhes.


## 👤 Autor

Desenvolvido por **Ivanilto Santos**

- 🔗 GitHub: [@ivaniltosantos](https://github.com/ivaniltosantos)