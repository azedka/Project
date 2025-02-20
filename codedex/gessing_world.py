import random

# Liste des mots possibles
word_bank = ['rizz', 'ohio', 'sigma', 'tiktok', 'skibidi']

# Choisir un mot aléatoire
word = random.choice(word_bank)

# Liste pour suivre les lettres devinées
guessedWord = ['_'] * len(word)

# Nombre de tentatives
attempts = 10

# Dessin du pendu
pendu = [
    "",

    """ -----
     
     
     
     
     """,

    """ ----- 
      |   
      |   
      |   
      |   
 ------
""",

    """  -----
  |   |
      |
      |
      |
      |
------
""",

    """  -----
  |   |
  O   |
      |
      |
      |
------
""",

    """  -----
  |   |
  O   |
  |   |
      |
      |
------
""",

    """  -----
  |   |
  O   |
 /|   |
      |
      |
------
""",

    """  -----
  |   |
  O   |
 /|\  |
      |
      |
------
""",

    """  -----
  |   |
  O   |
 /|\  |
 /    |
      |
------
""",

    """  -----
  |   |
  O   |
 /|\  |
 / \  |
      |
------
"""
]

# Compteur des tentatives incorrectes
pendu_attempt = 0

# Boucle principale du jeu
while attempts > 0:
    print('\nCurrent word: ' + ' '.join(guessedWord))

    # Demander à l'utilisateur de deviner une lettre
    guess = input('Guess a letter: ').lower()
    
    # Vérifier si la lettre est dans le mot
    if guess in word:
        for i in range(len(word)):
            if word[i] == guess:
                guessedWord[i] = guess
        print('Great guess!')
    else:
        attempts -= 1
        print(pendu[pendu_attempt])
        pendu_attempt += 1
        print('Wrong guess! Attempts left: ' + str(attempts))
    
    # Vérifier si l'utilisateur a trouvé le mot
    if '_' not in guessedWord:
        print('\nCongratulations!! You guessed the word: ' + word)
        break
else:
    # Message lorsque toutes les tentatives sont épuisées
    print('\nYou\'ve run out of attempts! The word was: ' + word)
