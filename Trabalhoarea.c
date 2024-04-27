#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Ponto{
    float x;
    float y;
};

float areatriangulo(struct Ponto v[], int tamanho){
  float areaTriangulo = 0;

  for (int i = 0; i < tamanho - 2; i++) {
      float M[3][3] = {
          {v[0].x, v[0].y, 1},
          {v[i + 1].x, v[i + 1].y, 1},
          {v[i + 2].x, v[i + 2].y, 1},
      };

      float det = 0;

      // Cálculo do determinante
      det = det + (M[0][0] * M[1][1] * M[2][2]);  
      det = det + (M[0][1] * M[1][2] * M[2][0]); 
      det = det + (M[0][2] * M[1][0] * M[2][1]);
      det = det - (M[2][0] * M[1][1] * M[0][2]);
      det = det - (M[2][1] * M[1][2] * M[0][0]);
      det = det - (M[2][2] * M[1][0] * M[0][1]);

      // Área do triângulo
      areaTriangulo += det / 2;
  }

  if (areaTriangulo < 0) {
      areaTriangulo = -areaTriangulo;
  }

  return areaTriangulo;
}

int main(void) {
    FILE *arquivo;
    int verticeTriangulo;
    float n1, n2;
    

    arquivo = fopen("trabalhoPoligono.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1); 
    }

    fscanf(arquivo, "%d", &verticeTriangulo);
    struct Ponto v[verticeTriangulo];

    // Ler e armazenar os valores
    for (int i = 0; i < verticeTriangulo; i++) {
        fscanf(arquivo, "%f %f", &n1, &n2);
        v[i].x = n1;
        v[i].y = n2;

    }


    float area = areatriangulo(v, verticeTriangulo);

    printf("A area do poligono é: %.2f", area);
    fclose(arquivo);

    return 0;
}

