/*
  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES
  DESSE EP E QUE PORTANTO NÃO CONSTITUEM DESONESTIDADE ACADÊMICA
  OU PLÁGIO.
  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS AS CÓPIAS
  DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO E
  DESONESTIDADE ACADÊMICA SERÃO TRATADOS SEGUNDO OS CRITÉRIOS
  DIVULGADOS NA PÁGINA DA DISCIPLINA.
  ENTENDO QUE EPS SEM ASSINATURA NÃO SERÃO CORRIGIDOS E,
  AINDA ASSIM, PODERÃO SER PUNIDOS POR DESONESTIDADE ACADÊMICA.

  Nome : Gabriel Gomes de Araujo Chollet
  NUSP : 12550685
  Turma: 01
  Prof.: Alair Pereira do Lago
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXM  100
#define MAXK  5
#define MAXP  32000
#define MAXD  100
#define MAXF  100
#define FALSE 0
#define TRUE  1



/*
Abaixo, temos o protótipo de algumas funções que você deve implementar
*/


int BuscaMarcador( int ini, char politech[MAXP], char marcador[MAXM] );
int BuscaMarcadores( int ini, char politech[MAXP],
		     int k, char marcadores[MAXK][MAXM], int *compr);
int Delta( char q[MAXP], char p[MAXP], int delta[MAXD], int desloc, int ini, int fim );
int DiferencaDeConjuntos( int delta_q[MAXD], int delta_s[MAXD], int q_menos_s[MAXD] );
int HaIncompatibilidade( int n, char F[MAXF][MAXP], int j_p, int G[MAXF], int D[MAXF][MAXD] );

/*
Você deve escrever o protótipo da função abaixo
 */
void DiametroEProbabilidades(int delta[MAXD], int ini, int fim, int *diametro, double *Prob_eq_diametro, double *Prob_le_diametro);

/*Fatorial de inteiros não-negativos*/
long double Fat(int n);

/*
Você pode escrever outras funções para lhe ajudar.
Por exemplo, uma função para calcular |T(n,k,d)| pode ser útil
*/





int main() {
  char F[MAXF][MAXP];		/* matriz com a família de Politechs, um por linha */
  int np = 0;	                /* número de Politechs armazenados em F */
  int ncp = 0;			/* total de caracteres dos Politechs de F */
  int j_p = 0;			/* indice do patriarca na família */
  int L[MAXF];		        /* length (comprimento) de cada politech */
  int G[MAXF];		        /* gama, primeira ocorrência de marcador de início */
  int continua = TRUE;		/* iteração continua?  */
  char comando;			/* comando selecionado */
  char m[MAXK][MAXM];		/* marcadores de início */
  int nm = 0;	                /* número de marcadores de início */
  char M[MAXK][MAXM];		/* marcadores de fim */
  int nM = 0;	                /* número de marcadores de fim */
  int i, j, k, compr;
  int ini = 0, fim = MAXP-1;	/* extremidades do intervalo de busca de caracteristicas */
  int D[MAXF][MAXD];		/* matriz de caracteristicas com Delta( F[i] ) em cada linha D[i] */
  int diametro;			/* valor devolvido por DiametroEProbabilidade */
  double Prob_eq_diametro, Prob_le_diametro; /* valores devolvidos por DiametroEProbabilidades */
  char comentario[300];			     /* linha de comentario */

  while( continua ) {
    printf( "Digite uma letra para um comando: " );
    comando = 'q';		/* valor default de leitura se houver erro no scanf */
    do {
      scanf( " %c", &comando );
      if ( comando == '#' ) {
	scanf( "%[^\n]",comentario );
	printf("\n#%s",comentario);
      }
    } while (comando=='#');
    switch( comando ) {
    case 'p':
      printf( "\nDigite um Politech: " );
      scanf( " %[!-~]", F[np] );
      L[np] = strlen( F[np] );
      ncp += L[np];
      printf( "\nPolitech %d de comprimento %d inserido na familia, com %d caractere(s).\n",
	      np, L[np], ncp );
      G[np] = D[np][0] = MAXP;	/* calculo posterior */
      np++;
      break;
    case 'P':
      printf( "\nDigite indice do patriarca: " );
      scanf( " %d", &j_p );
      ini = 0, fim = strlen( F[j_p] ) - 1;
      printf( "\nPatriarca da familia [ %d .. %d ] eh o de numero %d e tem comprimento %d .\n",
	      0, np-1, j_p, fim + 1 );
      break;
    case 'e':
      printf( "\nExtremidades atuais do intervalo de posicoes do patriarca a ser comparado: %d %d", ini, fim );
      if ( nm > 0 )
	printf( "\nPrimeira ocorrencia de um marcador de inicio: %d",
		BuscaMarcadores( ini, F[j_p], nm, m, &compr ) );
      printf("\nDigite duas novas extremidades do intervalo de onde serao extraidas as caracteristicas\n(valores invalidos provocam uma busca automatica que use os conjuntos de marcadores): ");
      scanf( "%d %d", &ini, &fim );
      if ( !( 0 <= ini && ini <= fim && fim < L[j_p] ) ) {
	/* valores invalidos provocam uma busca automatica */
	ini = 0; fim = L[j_p];
	printf( "\nAntigo interv. de busca de caracteristicas: [ %d .. %d ].", ini, fim );
	i = ini; k = -1;
	do {
	  /* busca marcador de início */
	  i = BuscaMarcadores( i, F[j_p], nm, m, &compr );
	  /* printf( "[ marca_ini compr =  %d %d\n", i, compr ); */
	  if ( i <= fim-compr ) {
	    i = i + compr;
	    /* busca marcador de fim */
	    j = BuscaMarcadores( i, F[j_p], nM, M, &compr );
	    /* printf( "marca_fim ] compr =  %d %d\n", j, compr ); */
	    if ( j <= fim-compr )
	      k = i = j + compr;
	    else if ( j == MAXP || j + compr > fim ) {
	      i = MAXP;
	      compr = 0;
	    }
	  } /* if i */
	} while ( i <= fim );
	if ( k >= 0) {
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	  fim = k;
	  ini = BuscaMarcadores( 0, F[j_p], nm, m, &compr );
	  /* para incluir mutações biológicas em regiões promotoras */
	  ini = ini < 10 ? 0 : ini-10;
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	}
      }
      printf( "\nNovo intervalo de busca de caracteristicas: [ %d .. %d ].\n", ini, fim );
      break;
    case 'm':
      assert( nm < MAXM );
      printf( "\nDigite um marcador de inicio: " );
      scanf( " %[!-~]", m[ nm++ ] );
      printf( "\nInserindo marcador de inicio: %s", m[ nm - 1 ] );
      printf( "  Temos %d marcador(es) de inicio.\n", nm );
      break;
    case 'M':
      assert( nM < MAXM );
      printf( "\nDigite um marcador de fim: " );
      scanf( " %[!-~]", M[ nM++ ] );
      printf( "\nInserindo marcador de fim: %s", M[ nM - 1 ] );
      printf( "  Temos %d marcador(es) de fim.\n", nM );
      break;
    case 'g':
      printf( "\nPrimeira ocorrencia de marcador de inicio (gama) de cada politech:\n%s",
	      "  i   gama" );
      for ( i = 0; i < np; i++ ) {
	G[i] = BuscaMarcadores( 0, F[i], nm, m, &compr );
	printf( "\n%3d %5d", i, G[i] );
      }
      printf("\n");
      break;
    case 'd':
      printf( "\nCaracteristicas no intervalo [ %d .. %d ]:", ini, fim );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  printf( "\nD[ %3d ] = ", i );
	  for ( j = 0; D[i][j] < MAXP; j++ )
	    printf( " %5d", D[i][j] );
	}
	else
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf("\n");
      break;
    case 'b':
      printf( "\nDiametros e Probabilidades do conjunto de caracteristicas:" );
      printf( "\npol     n   k     d  P(diam=d) P(diam<=d)" );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  DiametroEProbabilidades( D[i], ini, fim, &diametro,
				       &Prob_eq_diametro, &Prob_le_diametro );
	  printf( "\n%3d %5d %3d %5d   %8.2e  %-8.3g",
		  i, fim - ini + 1, k, diametro, Prob_eq_diametro, Prob_le_diametro );
	}
	else
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf( "\n" );
      break;
    case 'i':
      if ( HaIncompatibilidade( np, F, j_p, G, D ) )
	printf( "\nHah caracteristicas incompativeis e nao hah arvore filogenetica perfeita.\n" );
      else
	printf( "\nNao hah caracteristicas incompativeis e hah arvore filogenetica perfeita.\n" );
      break;
    default:
      printf( "\nComando invalido: %c\n", (int) comando );
    case 'q':
      continua = FALSE;
      printf( "\nObrigado, ate mais.\n" );
      break;
    }
  }
  return 0;
}


int BuscaMarcador( int ini, char politech[MAXP], char marcador[MAXM] )
{
    for (int j = 0; ini < strlen(politech); ini++)
    {
        if (marcador[j] == politech[ini])
        {
            j++;
        }
        else
        {
            j = 0;
        }
        if (marcador[j] == '\0' && marcador[0] != '\0')
        {
            return ini - j + 1;
        }
    }
    return MAXP;
}

int BuscaMarcadores( int ini, char politech[MAXP], int k, char marcadores[MAXK][MAXM], int *compr)
{
    int pos[MAXK];
    int first_marker;

    /*encrontrar a primeira ocorrencia de qualquer um dos k marcadores e
      encontra o comprimento do primeiro marcador encontrado*/
    for (int i = 0; i <= k; i++)
    {
        pos[i] = BuscaMarcador(ini, politech, marcadores[i]);
    }

    first_marker = pos[0];
    for (int z = 0; z < k - 1; z++)
    {
        if (pos[z] > pos[z + 1])
        {
            first_marker = pos[z + 1];
            if (first_marker != MAXP)
            {
                *compr = strlen(marcadores[z + 1]);
            }
            else
            {
                compr = 0;
            }
        }
    }

    return first_marker;
}

int Delta( char q[MAXP], char p[MAXP], int delta[MAXD], int desloc, int ini, int fim )
{
    int z = 0; /*numero de diferencas*/
    for (int i = 0; i + ini <= fim; i++)
    {
        if (p[i + ini] != q[i + ini + desloc])
        {
            delta[z] = i + ini;
            z++;
        }
    }

    delta[z] = MAXP;

    return z;
}

long double Fat(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n*Fat(n - 1);
    }
    /*
    double fatorial = 1;

    for (int i = n; i > 0; i--) {
        fatorial *= i;
    }

    return fatorial;
    */
}

void DiametroEProbabilidades(int delta[MAXD], int ini, int fim, int *diametro, double *Prob_eq_diametro, double *Prob_le_diametro)
{
    int i = 0, k = 0, n = fim - ini + 1, prob_menor = 0;

    while (delta[k] != MAXP && delta[k] >= ini && delta[k] <= fim)
    {
        k++;
    }

    *diametro = 1 + delta[k] - delta[0];

    /*probabilidade para conjuntos com mesmo diametro*/
    if (*diametro == k && *diametro == 1)
    {
        *Prob_eq_diametro = 1;
        *Prob_le_diametro = 0;
    }
    else if (n >= *diametro && *diametro >= k && k >= 2)
    {
        *Prob_eq_diametro = (Fat(n - k) / Fat(n))*(n - *diametro + 1)*k*(k - 1)*Fat(*diametro - 2)/Fat(*diametro - k);
        /*probabilidade para conjuntos com diâmetros não superiores*/
        for (i = *diametro; i >= k; i--)
        {
            prob_menor += (Fat(n - k) / Fat(n))*(n - i + 1)*k*(k - 1)*Fat(i - 2)/Fat(i - k);
        }
        *Prob_le_diametro = prob_menor + *Prob_eq_diametro;
    }

    return;
}

int DiferencaDeConjuntos( int delta_q[MAXD], int delta_s[MAXD], int q_menos_s[MAXD] )
{
    int len_q = 0, len_s = 0, k = 0,
     ret = 0; /*numero de elementos comuns a delta_q e delta_s*/
    while (delta_q[len_q] != MAXP)
    {
        len_q++;
    }
    while (delta_s[len_s] != MAXP)
    {
        len_s++;
    }
    for (int i = 0, a = 0; delta_q[i] != MAXP; i++)
    {

        k = 0;

        for (int j = 0; delta_s[j] != MAXP; j++)
        {
            if (delta_q[i] != delta_s[j])
            {
                k++;
            }
        }
        if (k == len_s)
        {
            q_menos_s[a] = delta_q[i];
            a++;
        }
        else
        {
            ret++;
        }
    }
    q_menos_s[len_q - ret] = MAXP;

    return len_q - ret;
}


int HaIncompatibilidade( int n, char F[MAXF][MAXP], int j_p, int G[MAXF], int D[MAXF][MAXD] )
{
    int len_q_s, len_s_q, q_menos_s[MAXD], s_menos_q[MAXD], c, d;
    char q[MAXP], s[MAXP], r[MAXP];

    for (int i = 0; i < n && i != j_p; i++)
    {
        for (int j = 0; j < n && j != i && j != j_p; j++)
        {
            len_q_s = DiferencaDeConjuntos(D[i], D[j], q_menos_s);
            len_s_q = DiferencaDeConjuntos(D[j], D[i], s_menos_q);

            for (int k = 0; k < n && k != j_p; k++)
            {
                if (D[i] == q_menos_s && D[j] == s_menos_q && D[i] == D[k] && D[j] == D[k] )
                {
                    //printf("  contraexemplo: q = %d    s = %d    c = %d     d = %d     r = %d", i, j, );
                }
            }
        }
    }

    return FALSE;
}
