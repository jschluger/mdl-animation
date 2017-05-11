def make_script():
    for theta in range( 0, 361, 5):
        print """
//base
push
push
push
move 250 250 0
rotate y 45
rotate x %d
        
//body
push
scale 1 .5 .5
sphere 0 0 0 100
        
//top
push
move 0 150 0
sphere 0 0 0 50

//back to body        
pop
//bottom
push
move 0 -150 0
sphere 0 0 0 50

//back to body
pop
//right
push
move 150 0 0
scale .5 2 2
sphere 0 0 0 50
        
//back to body
pop
//left
push
move -150 0 0
scale .5 2 2
sphere 0 0 0 50

save frame%s.png
pop
pop

        """ % ( theta, format(theta/5) )

def format( x ):
    if x < 10:
        num = "00%d"
    elif x < 100:
        num = "0%d"
    else:
        num = "%d"
    return num % x
        
    
make_script()
