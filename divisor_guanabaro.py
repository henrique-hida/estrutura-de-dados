import random

def dividir_exercicios(guanabaros: list, num_exercicios: int) -> dict:
    exercicios = list(range(1, num_exercicios + 1))
    random.shuffle(exercicios)
    
    num_guanabaros = len(guanabaros)
    
    exercicios_por_guanabaro = num_exercicios // num_guanabaros
    exercicios_restantes = num_exercicios % num_guanabaros
    
    atribuicao = {guanabaro: [] for guanabaro in guanabaros}
    
    idx_exercicio = 0
    for guanabaro in guanabaros:
        for _ in range(exercicios_por_guanabaro):
            atribuicao[guanabaro].append(exercicios[idx_exercicio])
            idx_exercicio += 1
            
    for i in range(exercicios_restantes):
        guanabaro_aleatorio = random.choice(guanabaro)
        
        atribuicao[guanabaro_aleatorio].append(exercicios[idx_exercicio])
        idx_exercicio += 1
        
    return atribuicao


# =====================================================================
guanabaro_str = "Enzo, Henrique, Thomas"
guanabaros = [guanabaro.strip() for guanabaro in guanabaro_str.split(',')]
num_exercicios = 15

divisao_de_tarefas = dividir_exercicios(guanabaros, num_exercicios)

for guanabaro, exercicios_atribuidos in divisao_de_tarefas.items():
    print(f"{guanabaro}: {exercicios_atribuidos}")