import time
import pyautogui
from tkinter import 
from pynput import keyboard

running = False
value = 1000

def detect_key(key)
    global window
    global running
    try
        if key == keyboard.Key.up
            start_auto_click()
        elif key == keyboard.Key.down
            stop_auto_click()
    except AttributeError
        pass

def auto_click()
    global window
    global running
    global value
    get_spinbox_value()

    if running
        pyautogui.click()
        window.after(int(value), auto_click)
        window.lift()

def get_spinbox_value()
    global value
    value = spinbox.get()

def start_auto_click()
    global running
    start_button.config(state=DISABLED)
    quit_button.config(state=DISABLED)
    running = True
    auto_click()

def stop_auto_click()
    global running
    start_button.config(state=NORMAL)
    quit_button.config(state=NORMAL)
    running = False

window = Tk()
window.title(auto click)
window.geometry(300x250)
window.iconbitmap(fermer-a-cle.ico)

frame = Frame(window)
frame.pack()

spinbox = Spinbox(window, from_=100, to=10000, width=10, font=('Arial', 30), bd=2)
spinbox.place(relx=0.5, rely=0.5, anchor=CENTER)

quit_button = Button(frame, text='QUITTER', font=('Arial', 10), bg='white', fg='black', command=window.quit)
quit_button.grid(row=0, column=2, sticky=W)

start_button = Button(frame, text='LANCER', font=('Arial', 10), bg='white', fg='black', command=start_auto_click)
start_button.grid(row=0, column=3, sticky=W)

# Ajouter la détection des touches de flèche en utilisant pynput
with keyboard.Listener(on_press=detect_key) as listener
    window.mainloop()
