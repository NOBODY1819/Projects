import random

def user_guess():
    random_number = random.randint(1,10)
    guess_number=int(input(f'Guess a number between 1 and 10 : '))
    while guess_number!=random_number:
        if guess_number> random_number:
            guess_number=int(input('Guess too High. Guess again     : '))
        elif guess_number < random_number:
            guess_number=int(input('Guess too Low. Guess again      : '))
    print(f'****Congrats. You guessed the number {random_number} correctly ****')
   
def computer_guess():
    low = 1
    high=10
    guess_number=0
    feedback=''
    while feedback!='c':
        if low < high:
            guess_number=random.randint(low,high)
        elif low > high:
            print('The number is already gussed.')
            break
        elif low ==high:
            guess_number=low
        feedback=input(f'Is the number {guess_number}?\nCorrect(c)\nToo High(h)\nToo low(l)     : ')        
        if feedback=='l':
            low= guess_number+1
        elif feedback=='h':
            high= guess_number-1
    print(f'****Hoo-ray!. Computer guessed the number correctly ****')

if __name__=='__main__':
    game=input('For user guess -> 1\nFor computer guess -> 2     : ')
    if game=='1':
        user_guess()
    elif game=='2':
        computer_guess()
    else:
        print('Invalid Choice')