import time
from tkinter import *

window = Tk()
click = 0
add = 1
price1 = 100
price2 = 1000

def clicked():
    global click
    global add
    click += add
    label_subtitle.config(text=click)

def shop1():
    global click
    global add
    global price1
    if click >= 100:
        add += 1
        click -= 100
        price1 *= 1.5
        X2_button.config(text=f'ACHETER |+ 1 click| (prix = {price1:.2f})')
        label_subtitle.config(text=click)

def auto_click():
    global click
    global add
    global price2
    if click >= 1000:
        click += add
        price2 *= 1.5
        auto_button.config(text=f'ACHETER |auto click| (prix = {price2:.2f})')
        label_subtitle.config(text=click)
        window.after(1000, auto_click)

window.title("cookie clicker")
window.geometry("400x1000")
window.minsize(1080, 760)
window.attributes('-fullscreen', True)
window.config(background='#7E5F58')
window.iconbitmap('test.ico')

frame1 = Frame(window, bg='#7E5F58')
frame1.grid(row=0, column=0, sticky=W)

frame2 = Frame(window, bg='#7E5F58')
frame2.grid(row=0, column=2, sticky=E)

label_title = Label(frame1, text="BIENVENUE SUR MON COOKIE CLICKER", font=('Comic Sans MS', 40), bg='#7E5F58', fg='white')
label_title.pack()

label_subtitle = Label(frame1, text=click, font=('Comic Sans MS', 30), bg='#7E5F58', fg='white')
label_subtitle.pack()

width = 300
height = 300
image = PhotoImage(file="img.png").zoom(100).subsample(32)
canvas = Canvas(frame1, width=width, height=height, bg='#7E5F58', bd=0, highlightthickness=0)
canvas.create_image(width/2, height/2, image=image)
canvas.pack()

cookies_button = Button(frame1, text='CLICK', font=('Comic Sans MS', 25), bg='white', fg='#7E5F58', command=clicked)
cookies_button.pack()

kit_button = Button(frame1, text='QUITTER', font=('Comic Sans MS', 25), bg='white', fg='#7E5F58', command=window.quit)
kit_button.pack()

shop_title = Label(frame2, text="BOUTIQUE", font=('Comic Sans MS', 30), bg='#7E5F58', fg='white')
shop_title.pack()

X2_button = Button(frame2, text=f'ACHETER |+ 1 click| (prix = {price1:.2f})', font=('Comic Sans MS', 25), bg='white', fg='#7E5F58', command=shop1)
X2_button.pack()

auto_button = Button(frame2, text=f'ACHETER |auto click| (prix = {price2:.2f})', font=('Comic Sans MS', 25), bg='white', fg='#7E5F58', command=auto_click)
auto_button.pack()

window.mainloop()
