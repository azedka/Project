import random

a = ""
b = ""
c = ""
d = ""
e = ""
f = ""
g = ""
h = ""
i = ""
def dem():
    global a, b, c, d, e, f, g, h, i
    a = ""
    b = ""
    c = ""
    d = ""
    e = ""
    f = ""
    g = ""
    h = ""
    i = ""
def grille():
    global a, b, c, d, e, f, g, h, i
    print("       0      1       2")
    print("    ----------------------")
    print(" 0  |  ", a,"  |  ", b, "  |  ", c,"  |")
    print("    -----------------------")
    print(" 1  |  ", d,"  |  ", e, "  |  ", f,"  |")
    print("    -----------------------")
    print(" 2  |  ", g,"  |  ", h, "  |  ", i,"  |")
    print("    ----------------------")
def questionsX():
    global a, b, c, d, e, f, g, h, i, li, co
    print("                                                      JOUEUR 1 (X) ")
    grille()
    li = int(input("colonne : "))
    co = int(input("ligne : "))
    print("colonne : ", li, ", ligne : ", co)
    if co == 0 and li == 0:
        if a == "":
            a = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 0 and li == 1:
        if b == "":
            b = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 0 and li == 2:
        if c == "":
            c = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 1 and li == 0:
        if d == "":
            d = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 1 and li == 1:
        if e == "":
            e = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 1 and li == 2:
        if f == "":
            f = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 2 and li == 0:
        if g == "":
            g = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 2 and li == 1:
        if h == "":
            h = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co == 2 and li == 2:
        if i == "":
            i = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsX()

    if co >= 3 and li >= 3:
        print('CHOIX NON-DISPONIBLE')
        questionsX()
def questionsO():
    global a,b,c,d,e,f,g,h,i,li,co
    print("                                                      JOUEUR 2 (O) ")
    grille()
    li = int(input("colonne : "))
    co = int(input("ligne : "))
    print("colonne : ", li, ", ligne : ", co)
    if co == 0 and li == 0:
        if a == "":
            a = "O"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 0 and li == 1:
        if b == "":
            b = "O"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 0 and li == 2:
        if c == "":
            c = "O"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 1 and li == 0:
        if d == "":
            d = "O"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 1 and li == 1:
        if e == "":
            e = "O"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 1 and li == 2:
        if f == "":
            f = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 2 and li == 0:
        if g == "":
            g = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 2 and li == 1:
        if h == "":
            h = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co == 2 and li == 2:
        if i == "":
            i = "X"
        else:
            print('CHOIX DEJA PRIS VEUILLEZ EN PRENDRE UN AUTRE')
            questionsO()

    if co >= 3 and li >= 3:
        print('CHOIX NON-DISPONIBLE')
        questionsO()
def pc():
    global li, co
    li = random.randint(0, 2)
    co = random.randint(0, 2)
def questionpc():
    global a, b, c, d, e, f, g, h, i, li, co
    print("                                                      ORDINATEUR (O) ")
    grille()
    pc()
    print("colonne : ", li, ", ligne : ",co)

    if co == 0 and li == 0:
        if a == "":
            a = "O"
        else:
            questionpc()

    if co == 0 and li == 1:
        if b == "":
            b = "O"
        else:
            questionpc()

    if co == 0 and li == 2:
        if c == "":
            c = "O"
        else:
            questionpc()

    if co == 1 and li == 0:
        if d == "":
            d = "O"
        else:
            questionpc()

    if co == 1 and li == 1:
        if e == "":
            e = "O"
        else:
            questionpc()

    if co == 1 and li == 2:
        if f == "":
            f = "O"
        else:
            questionpc()

    if co == 2 and li == 0:
        if g == "":
            g = "O"
        else:
            questionpc()

    if co == 2 and li == 1:
        if h == "":
            h = "O"
        else:
            questionpc()

    if co == 2 and li == 2:
        if i == "":
            i = "O"
        else:
            questionpc()
def jeu():
    while True:
        questionsX()
        if a == b == c == "X" or a == d == g == "X" or d == e == f == "X" or h == g == i == "X" or b == e == h == "X" or c == f == i == "X" or a == e == i == "X" or g == e == c == "X":
            grille()
            print("Joueur 1 (X) a gagné !")
            dem()
            break

        questionsO()
        if a == b == c == "O" or a == d == g == "O" or d == e == f == "O" or h == g == i == "O" or b == e == h == "O" or c == f == i == "O" or a == e == i == "O" or g == e == c == "O":
            grille()
            print("Joueur 2 (O) a gagné !")
            dem()
            break
def jeupc():
    while True:
        questionsX()
        if a == b == c == "X" or a == d == g == "X" or d == e == f == "X" or h == g == i == "X" or b == e == h == "X" or c == f == i == "X" or a == e == i == "X" or g == e == c == "X":
            grille()
            print("Joueur 1 (X) a gagné !")
            dem()
            break

        questionpc()
        if a == b == c == "O" or a == d == g == "O" or d == e == f == "O" or h == g == i == "O" or b == e == h == "O" or c == f == i == "O" or a == e == i == "O" or g == e == c == "O":
            grille()
            print("L ordinateur (O) a gagné !")
            dem()
            break
def iaounon():
    debut = int(input("Voulez vous jouer a 2 ou contre l'ordinateur ?(1 ou 2) : "))
    if debut == 1:
        jeu()
    elif debut == 2:
        jeupc()
    else:
        print("MODE INDISPONIBLE OU INEXISTANT")

while True:
    iaounon()
    re = input("Voulez vous rejouer ?(oui/non) : ")
    if re == 'non':
        break
