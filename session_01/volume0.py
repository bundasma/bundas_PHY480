pi = 3.141592653589793    # put in \pi by hand

answer = input('Enter the radius of a circle: ')  # answer is a string
radius = float(answer)   # convert to floating point number

volume = pi * radius**3 * (4/3)    # area formula; x**n is x to the n'th power

# simple printing (illustrates that either type of quotes can be used)

print ("radius = ", radius, ", volume = ", volume)
