
import numpy as np

# Parâmetros iniciais
t_0 = 0     # tempo inicial
v_0 = 5     # velocidade inicial
y_0 = 200   # altitude inicial
k = 0.25    # constante de aerodinâmica
m = 2       # massa do objeto
g = 10      # gravidade

dts_ls = [0.1, 0.01, 0.001, 0.0001]  # diferentes passos de tempo

# Método de Runge-Kutta de terceira ordem
def runge_kutta_3rd(t_0, v_0, y_0, k, m, g, dt):

    s_0 = np.array([v_0, y_0])
    y_max = y_0
    t_max = t_0
    v_final = 0

    while s_0[1] >= 0:  # Enquanto o objeto estiver acima do solo

        F_0 = np.array([-g - (k/m) * s_0[0], s_0[0]])

        # Calcular k1, k2, k3
        k1 = dt * F_0
        k2 = dt * np.array([-g - (k/m) * (s_0[0] + 0.5*k1[0]), s_0[0] + 0.5*k1[0]])
        k3 = dt * np.array([-g - (k/m) * (s_0[0] + 3*k2[0]/4), s_0[0] + 3*k2[0]/4])

        # Atualizar o estado s_1
        s_1 = s_0 + (1/9)*(2*k1 + 3*k2 + 4*k3)

        t_0 += dt
        v_final = s_1[0]
        s_0 = s_1
        
        if s_0[1] > y_max:
            y_max = s_0[1]
            t_max = t_0
    
    print(f"Δt                = {dt}:")
    print(f"altura_max        = {y_max}")
    print(f"tempo_max_altura  = {t_max}")
    print(f"tempo_total       = {t_0}")
    print(f"velocidade_final  = {abs(v_final)}\n\n")

# Executar para diferentes passos de tempo
for dt in dts_ls:
    runge_kutta_3rd(t_0, v_0, y_0, k, m, g, dt)


'''import numpy as np

t_0 = 0     # tempo inicial
v_0 = 5     # velocidade inicial
y_0 = 200   # altitude inicial
k = 0.25    # constante de aerodinâmica
m = 2       # massa do objeto
g = 10      # gravidade

dts_ls = [0.1, 0.01, 0.001, 0.0001]

# Método de Runge-Kutta de terceira ordem
def runge_kutta(t_0, v_0, y_0, k, m, g, dt):

    s_0 = np.array([v_0, y_0])
    s_1 = np.array([v_0, y_0])
    y_max = y_0
    t_max = t_0
    v_final = 0

    while (s_0[1] >= 0): # Enquanto o objeto estiver acima do solo
        F_0 = np.array([-g-(k/m * s_0[0]), s_0[0]])

        #Estimativa de Si+1/2
        s_meio = s_0 + (dt/2) * F_0
        v_meio = s_meio[0]
        y_meio = s_meio[1]

        #Estimativa de Si+1
        s_1 = s_0 + dt * F_0
        v_1 = s_1[0]
        y_1 = s_1[1]
        
        #Atualização melhorada do estado Si+1
        s_1 = s_0 + dt *((1/6)*F_0 + (4/6)*(np.array([-g-(k/m * v_meio), v_meio])) + (1/6)*(np.array([-g-(k/m * v_1), v_1])))

        t_0 = t_0 + dt
        v_final = s_1[0]
        s_0 = s_1
        if s_0[1] > y_max:
            y_max = s_0[1]
            t_max = t_0
    
    print(f"Δt                = {dt}:")
    print(f"altura_max        = {y_max}")
    print(f"tempo_max_altura  = {t_max}")
    print(f"tempo_total       = {t_0-dt}")
    print(f"velocidade_final  = {abs(v_final)}\n\n")

for dt in dts_ls:
    runge_kutta(t_0, v_0, y_0, k, m, g, dt)'''