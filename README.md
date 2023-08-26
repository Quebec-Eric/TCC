# TCC

# Partição de Inteiros com Rademacher em C++

## Descrição

Este projeto implementa o cálculo da função de partição de inteiros, \( p(n) \), usando a fórmula de Rademacher. A fórmula é dada por:

![Equação para p(n)](/imagens/pn.svg)

Onde \( A_k(n) \) é definido como:

![Equação para A_k(n)](/imagens/ak.svg)


## Requisitos

- Compilador C++ (recomendado: GCC ou Clang)
- Biblioteca GNU Multiple Precision Arithmetic (GMP)

## Instalação no Arch Linux

### Compilador C++

Para instalar o compilador GCC:

\```bash
sudo pacman -S base-devel
\```

### Biblioteca GMP

Para instalar a biblioteca GMP:

\```bash
sudo pacman -S gmp
\```

## Compilação e Execução

Compile o programa com:

\```bash
g++ main.cpp -lgmp -o partition
\```

Execute o programa com:

\```bash
./partition
\```

## Estrutura do Código

1. **Função `compute_Ak`**: Calcula \( A_k(n) \) usando a série de Fourier.
2. **Função `compute_derivative`**: Calcula a derivada da função hiperbólica seno.
3. **Função `compute_partition`**: Implementa a fórmula de Rademacher para calcular \( p(n) \).

## Uso

Após a execução, o programa solicitará um número inteiro \( n \) e retornará o valor de \( p(n) \).

\```bash
Enter an integer n: 5
Partition of 5: 7
\```

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir um Pull Request ou Issue.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo `LICENSE.md` para mais detalhes.
