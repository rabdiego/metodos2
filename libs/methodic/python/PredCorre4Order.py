import numpy as np
from RungeKutta4Order import runge_kutta_4rd2

# Parâmetros iniciais
t_0 = 0     # tempo inicial
v_0 = 5     # velocidade inicial
y_0 = 200   # altitude inicial
k = 0.25    # constante de aerodinâmica
m = 2       # massa do objeto
g = 10      # gravidade

dts_ls = [0.1, 0.01, 0.001, 0.0001]  # diferentes passos de tempo


def calcular_forca(s, k, m, g):
    v = s[0]
    F = np.array([-g - (k/m) * v, v])
    return F
# Método preditor-corretor de quarta ordem

def pred_corre_4rd(t_0, v_0, y_0, k, m, g, dt):
    y_max = y_0
    t_max = t_0
    v_final = 0
    
    S0 = np.array([v_0, y_0])
    S1 = runge_kutta_4rd2(t_0, S0[0], S0[1], k, m, g, dt)
    S2 = runge_kutta_4rd2(t_0, S1[0], S1[1], k, m, g, dt)
    S3 = runge_kutta_4rd2(t_0, S2[0], S2[1], k, m, g, dt)

    # Calcular as forças para os estados iniciais
    F_0 = calcular_forca(S0, k, m, g)
    F_1 = calcular_forca(S1, k, m, g)
    F_2 = calcular_forca(S2, k, m, g)
    F_3 = calcular_forca(S3, k, m, g)

    S4_0 = S3 + (dt/24)*(55*F_3 - 59*F_2 + 37*F_1 - 9*F_0)

    F_4_0 = calcular_forca(S4_0, k, m, g)

    while S4_0[1] >= 0:  # Enquanto o objeto estiver acima do solo
        S4_1 = S3 + (dt/24)*(9*F_4_0 + 19*F_3 - 5*F_2 + F_1)
        F_4_1 = calcular_forca(S4_1, k, m, g)
    

        t_0 += dt
        v_final = S4_1[0]
        S4_0 = S4_1
        F_4_0 = F_4_1
        
        S0, S1, S2, S3 = S1, S2, S3, S4_1  # Atualizar os estados
        F_0, F_1, F_2, F_3 = F_1, F_2, F_3, F_4_1  # Atualizar as forças
        
        if S4_0[1] > y_max:
            y_max = S4_0[1]
            t_max = t_0

    print(f"Δt                = {dt}:")
    print(f"altura_max        = {y_max}")
    print(f"tempo_max_altura  = {t_max}")
    print(f"tempo_total       = {t_0}")
    print(f"velocidade_final  = {abs(v_final)}\n\n")


for dt in dts_ls:
    pred_corre_4rd(t_0, v_0, y_0, k, m, g, dt)




    