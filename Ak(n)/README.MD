# README: Desenvolvimento da Fórmula Matemática

## Introdução
O código C++ com MPFR realiza uma série de cálculos para calcular um número complexo. O cálculo é baseado na fórmula \( A_k(n) = \sum_{m=1}^{k-1} e^{\pi i \left( \frac{m^2}{k} \right)} e^{- 2 \pi i \left( \frac{mn}{k} \right) }\).

## Desenvolvimento da Fórmula
1. **Termo Complexo da Exponencial para \( m^2/k \)**
    ```
    e^{\pi i \left( \frac{m^2}{k} \right)} = \cos\left(\pi \frac{m^2}{k}\right) + i \sin\left(\pi \frac{m^2}{k}\right)
    ```

2. **Termo Complexo da Exponencial para \( -2mn/k \)**
    ```
    e^{-2\pi i \left( \frac{mn}{k} \right)} = \cos\left(-2\pi \frac{mn}{k}\right) + i \sin\left(-2\pi \frac{mn}{k}\right)
    ```

3. **Multiplicação dos Termos Complexos**
    ```
    \left( \cos\left(\pi \frac{m^2}{k}\right) + i \sin\left(\pi \frac{m^2}{k}\right) \right) \times \left( \cos\left(-2\pi \frac{mn}{k}\right) + i \sin\left(-2\pi \frac{mn}{k}\right) \right)
    ```

4. **Expansão e Simplificação**
    ```
    = \cos\left(\pi \frac{m^2}{k} - 2\pi \frac{mn}{k}\right) + i \sin\left(\pi \frac{m^2}{k} - 2\pi \frac{mn}{k}\right)
    ```

## Fórmula Final Simplificada
A fórmula final após a simplificação é:
Z_1 \times Z_2 = \cos\left( A_k(n) \frac{\pi m^2}{k} - \frac{2 \pi m n}{k} \right) + i \sin\left( A_k(n) \frac{\pi m^2}{k} - \frac{2 \pi m n}{k} \right)
