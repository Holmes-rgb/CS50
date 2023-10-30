from cs50 import get_char
c = get_char("Do you agree?")

if c == 'y' or c == 'Y':
    print "Agreed."
    
elif c == 'n' or c ==  'N':
    print "Not agreed."