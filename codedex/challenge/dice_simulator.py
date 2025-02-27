import time
import random

continued = ""
dice_3d = [
    """
    -------
   |       |
   |   O   |
   |       |
    -------
    """,  

    """
    -------
   | O     |
   |       |
   |     O |
    -------
    """,  

    """
    -------
   | O     |
   |   O   |
   |     O |
    -------
    """,  

    """
    -------
   | O   O |
   |       |
   | O   O |
    -------
    """,  

    """
    -------
   | O   O |
   |   O   |
   | O   O |
    -------
    """,  

    """
    -------
   | O   O |
   | O   O |
   | O   O |
    -------
    """  
]

while True:
    
    continued = input("Do you want to reroll (yes/no) : ").lower()
    if continued == "yes":
            x = 0.05
            for i in range(0, 10):
                
                rdm = random.choice(dice_3d)
                print(rdm)
                x *= 1.2
                time.sleep(x)

            print(rdm)
    else:
        break
        


        