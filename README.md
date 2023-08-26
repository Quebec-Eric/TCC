# TCC

# Partição de Inteiros com Rademacher em C++

## Descrição

Este projeto implementa o cálculo da função de partição de inteiros, \( p(n) \), usando a fórmula de Rademacher. A fórmula é dada por:

\[
p(n) = \frac{1}{\pi \sqrt{2}} \sum_{k=1}^{\infty} A_k(n) \sqrt{k} \frac{d}{dn} \left( \frac{\sinh \left\{ \frac{\pi}{k} \sqrt{\frac{2}{3}(n - \frac{1}{24})} \right\}}{\sqrt{n - \frac{1}{24}}} \right)
\]

Onde \( A_k(n) \) é definido como:

\[
A_k(n) = \sum_{m=1}^{k-1} e^{\pi i \left( \frac{m^2}{k} \right)} e^{- 2 \pi i \frac{mn}{k}}
\]

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
