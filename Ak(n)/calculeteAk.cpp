#include <iostream>
#include <mpfr.h>


struct ComplexNumber
{
    mpfr_t real;
    mpfr_t imag;
};


void initComplexNumber(ComplexNumber &number,mpfr_prec_t bitsvalue){
    mpfr_init2(number.real, bitsvalue);
    mpfr_init2(number.imag, bitsvalue);
    mpfr_set_d(number.real, 0.0, MPFR_RNDN);
    mpfr_set_d(number.imag, 0.0, MPFR_RNDN);
}


void cleanMemoriOFCOmplexNumber(ComplexNumber &number){
    mpfr_clear(number.real);
    mpfr_clear(number.imag);
}


void turningComplexNumberInResult(ComplexNumber &result, ComplexNumber &tmp){
    mpfr_add(result.real, result.real, tmp.real, MPFR_RNDN);
    mpfr_add(result.imag, result.imag, tmp.imag, MPFR_RNDN);
}


void compleXNumberMutiply(ComplexNumber &result, ComplexNumber &number1,ComplexNumber &number2){

    mpfr_t tmp_real;
    mpfr_t tmp_imag;
    
    
    mpfr_init2(tmp_real, 256);
    mpfr_init2(tmp_imag, 256);


    mpfr_mul(tmp_real, number1.real, number2.real, MPFR_RNDN);
    mpfr_mul(tmp_imag, number1.imag, number2.imag, MPFR_RNDN);
    mpfr_sub(tmp_real, tmp_real, tmp_imag, MPFR_RNDN);

    mpfr_mul(tmp_imag, number1.real, number2.imag, MPFR_RNDN);
    mpfr_mul(result.imag, number1.imag, number2.real, MPFR_RNDN);
    mpfr_add(result.imag, tmp_imag, result.imag, MPFR_RNDN);

    mpfr_set(result.real, tmp_real, MPFR_RNDN);

    mpfr_clear(tmp_real);
    mpfr_clear(tmp_imag);

}

void perform_calculation(ComplexNumber &result, int m, int k, int n, mpfr_t &pi) {
    mpfr_t m_square, k_reciprocal, two_pi_mn_k;
    ComplexNumber temp1, temp2;
    mpfr_prec_t prec = 256;

    mpfr_init2(m_square, prec);
    mpfr_init2(k_reciprocal, prec);
    mpfr_init2(two_pi_mn_k, prec);
    initComplexNumber(temp1, prec);
    initComplexNumber(temp2, prec);

    // Realizando os cálculos 
    mpfr_set_si(m_square, m * m, MPFR_RNDN);
    mpfr_set_si(k_reciprocal, k, MPFR_RNDN);
    mpfr_div(m_square, m_square, k_reciprocal, MPFR_RNDN);

    mpfr_mul(temp1.real, pi, m_square, MPFR_RNDN);
    mpfr_cos(temp1.real, temp1.real, MPFR_RNDN);  
    mpfr_sin(temp1.imag, temp1.real, MPFR_RNDN);  

    mpfr_set_si(two_pi_mn_k, -2 * m * n, MPFR_RNDN);
    mpfr_div(two_pi_mn_k, two_pi_mn_k, k_reciprocal, MPFR_RNDN);
    mpfr_mul(two_pi_mn_k, pi, two_pi_mn_k, MPFR_RNDN);
    mpfr_cos(temp2.real, two_pi_mn_k, MPFR_RNDN); 
    mpfr_sin(temp2.imag, two_pi_mn_k, MPFR_RNDN); 

    compleXNumberMutiply(temp1, temp1, temp2);  
    turningComplexNumberInResult(result, temp1);           

    // desalocar da memoria
    mpfr_clear(m_square);
    mpfr_clear(k_reciprocal);
    mpfr_clear(two_pi_mn_k);
    cleanMemoriOFCOmplexNumber(temp1);
    cleanMemoriOFCOmplexNumber(temp2);
}
