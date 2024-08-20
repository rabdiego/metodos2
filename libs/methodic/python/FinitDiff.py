import numpy as np

N = 8
x_inicio = 0
x_fim = 1
y_inicio = 1
y_fim = 2
h = (x_fim - x_inicio) / N

x_0 = 0
y_0 = 0
x_1 = 1
y_1 = 1

F_0_1 = np.array([y_0,x_0])
F_1_1 = np.array([y_1,x_1])

def FinitDiff1(h, F_0_1, F_1_1, N):

    cel_esq = (1/h)**2
    cel_dir = (1/h)**2
    cel_meio = -((2/(h**2))+1)

    v_inicio = -(cel_esq * F_0_1[0])
    v_fim = -(cel_dir * F_1_1[0])

    A = np.zeros((N-1, N-1))  # Inicializa A como uma matriz N x N de zeros
    vetor = np.zeros(N-1)  # Inicializa vetor com N elementos

    for i in range(1, N-2):  # Loop de 1 até N-2 para evitar sobrescrita de A[0] e A[N-1]
        vetor = np.zeros(N-1)
        vetor[i-1] = cel_esq
        vetor[i] = cel_meio
        vetor[i+1] = cel_dir
        A[i] = vetor

    # Ajusta a primeira e a última linha de A para as condições de contorno
    A[0, 0] = cel_meio
    A[0, 1] = cel_dir
    A[-1, -2] = cel_esq
    A[-1, -1] = cel_meio

    print("Matriz A:\n", A)
    
    # Preenche o vetor b
    b = np.zeros(N-1)  # Inicializa b com N elementos
    b[0] = v_inicio
    b[-1] = v_fim

    print("Vetor b:", b)

    y = np.linalg.solve(A, b)
    print("Solução para o sistema (y1, y2, y3):", y)
FinitDiff1(h, F_0_1, F_1_1, N)

x_0 = np.array([0,0])
y_0 = 0
x_1 = np.array([0,1])
y_1 = 0
x_2 = np.array([0,0])
y_2 = 0
x_3 = np.array([1,0])
y_3 = 0

delta_x = (x_3[0] - x_2[0]) / N
delta_y = (x_1[1] - x_0[1]) / N
value = 4


def FinitDiff2(delta_x, delta_y,value, N):
    cel_x = (1/delta_x)**2
    cel_y = (1/delta_y)**2
    cel_meio = -2*((1/(delta_x**2))+(1/(delta_y**2)))

    aux = (N-1)**2
    A = np.zeros((aux, aux))  
    k = 0
    y = 0
    for i in range(aux):
        if i>0:
            k = k+1
            if k%(N-1) != 0:
                A[i][i-1] = cel_y
            else:
                A[i][i-1] = 0  
        if i > N-2:
            A[i][i-(N-1)] = cel_x

        A[i][i] = cel_meio

        if i < aux-(N-1):
            A[i][i+N-1] = cel_x

        if i< aux-1:
            y += 1
            if y%(N-1)!=0:
                A[i][i+1] = cel_y
            else:
                A[i][i+1] = 0

    print(A)
    
    b = np.array([value for i in range(aux)])  
    print(b)
    y = np.linalg.solve(A, b)
    return y

solucao = FinitDiff2(delta_x, delta_y, value, N)
print(f"Solucao: {solucao}")