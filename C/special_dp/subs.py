max_digits = 1024;
mod_max = 10;
mod_max **= 9;
mod_val = mod_max + 7; 

def print_arr(digits, len):
	for i in range(len):
		for j in range(len):
			print "digits at :", i , j, digits[i][j];

def get_the_subs():
	test_nums = input();

	for x in range(test_nums):
		num = input();
		#print "The count is :", get_the_count(str(num));
		print  get_the_count(str(num));

	return;

def try_subs():
	num = input();
	print "The count is :", get_the_count(str(num));
	return;

def get_the_count(digits):

	t_digits = [['' for x in range(max_digits)] for x in range(max_digits)];
	count = 0L;
	num_len = len(digits); 

	for i in range(num_len):
		for j in range (i):
			t_c = 0;
			t_c = (int(t_digits[j][i-1]) * 10) + int(digits[i]);
			count = (count + (t_c % mod_val)) % mod_val;
			t_digits[j][i] = str(t_c);
		count = (count + int(digits[i]) % mod_val) % mod_val;
		t_digits[i][i] = digits[i];

	#print_arr(t_digits, num_len);
	return count;



print "the mod val is:", mod_val;
get_the_subs();
#try_subs();
