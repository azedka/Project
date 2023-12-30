import keyboard
import time

def appuyer_sur_nombres_entree():
    # Délai initial pour donner du temps pour activer la fenêtre où l'entrée doit être saisie
    time.sleep(5)

    # Répéter l'action 100 fois
    for number in range(1, 301):
        # Écrire le nombre et appuyer sur Entrée
        keyboard.write(str(number))
        keyboard.press_and_release("enter")

        # Délai entre chaque itération (facultatif)
        time.sleep(0.001)

# Appeler la fonction
appuyer_sur_nombres_entree()
