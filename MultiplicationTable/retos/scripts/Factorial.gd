class_name Factorial

var fac = 0
var to_str = ''
var to_int = 0


func set_factorial(var fac: int):
	self.fac = fac
	self.to_str = String(fac) + '!'
	self.to_int = __calculate_factorial__(fac)


func __calculate_factorial__(var number : int):
	var result : int = 1
	
	if number <= 0:
		return 1
		
	for x in range(1, number + 1):
		result *= x
		
	return result