#include <iostream>
#include <mpfr.h>
#include <cmath>

struct ComplexMPFR {
    mpfr_t real, imag;

    ComplexMPFR(mpfr_prec_t prec) {
        mpfr_init2(real, prec);
        mpfr_init2(imag, prec);
    }

    ~ComplexMPFR() {
        mpfr_clear(real);
        mpfr_clear(imag);
    }
};

// Inicializa as variáveis ​​MPFR
void init_mpfr_vars(mpfr_t &pi, mpfr_prec_t prec) {
    mpfr_init2(pi, prec);
    mpfr_const_pi(pi, MPFR_RNDN);
}

// Realiza cálculos e adiciona ao resultado
void perform_calculation(ComplexMPFR &result, int m, int k, int n, mpfr_t &pi, mpfr_prec_t prec) {
    mpfr_t m_square, k_reciprocal, two_pi_mn_k, temp1, temp2;
    mpfr_t cos_part, sin_part;

    mpfr_init2(m_square, prec);
    mpfr_init2(k_reciprocal, prec);
    mpfr_init2(two_pi_mn_k, prec);
    mpfr_init2(temp1, prec);
    mpfr_init2(temp2, prec);
    mpfr_init2(cos_part, prec);
    mpfr_init2(sin_part, prec);

    mpfr_set_si(m_square, m * m, MPFR_RNDN);
    mpfr_set_si(k_reciprocal, k, MPFR_RNDN);
    mpfr_div(m_square, m_square, k_reciprocal, MPFR_RNDN);

    mpfr_mul(temp1, pi, m_square, MPFR_RNDN);
    mpfr_cos(cos_part, temp1, MPFR_RNDN);
    mpfr_sin(sin_part, temp1, MPFR_RNDN);

    mpfr_set_si(two_pi_mn_k, -2 * m * n, MPFR_RNDN);
    mpfr_div(two_pi_mn_k, two_pi_mn_k, k_reciprocal, MPFR_RNDN);
    mpfr_mul(two_pi_mn_k, pi, two_pi_mn_k, MPFR_RNDN);
    mpfr_cos(temp1, two_pi_mn_k, MPFR_RNDN);
    mpfr_sin(temp2, two_pi_mn_k, MPFR_RNDN);

    mpfr_mul(cos_part, cos_part, temp1, MPFR_RNDN);
    mpfr_mul(sin_part, sin_part, temp2, MPFR_RNDN);

    
    mpfr_add(result.real, result.real, cos_part, MPFR_RNDN);
    mpfr_add(result.imag, result.imag, sin_part, MPFR_RNDN);

    // Limpa as variáveis MPFR
    mpfr_clear(m_square);
    mpfr_clear(k_reciprocal);
    mpfr_clear(two_pi_mn_k);
    mpfr_clear(temp1);
    mpfr_clear(temp2);
    mpfr_clear(cos_part);
    mpfr_clear(sin_part);
}

int main() {
    mpfr_t pi;
    mpfr_prec_t prec = 256; 
    init_mpfr_vars(pi, prec);

    ComplexMPFR result(prec);
    mpfr_set_d(result.real, 0.0, MPFR_RNDN);
    mpfr_set_d(result.imag, 0.0, MPFR_RNDN);

    int k = 2;
    int n = 5;

    for (int m = 1; m < k ; ++m) {
        perform_calculation(result, m, k, n, pi, prec);
    }

    mpfr_exp_t exponent_real, exponent_imag;
    char *str_real = mpfr_get_str(NULL, &exponent_real, 10, 0, result.real, MPFR_RNDN);
    char *str_imag = mpfr_get_str(NULL, &exponent_imag, 10, 0, result.imag, MPFR_RNDN);

    std::cout << "Result = " << str_real << "e" << exponent_real - 1 << " + " << str_imag << "e" << exponent_imag - 1 << "i" << std::endl;

    mpfr_clear(pi);
    return 0;
}
