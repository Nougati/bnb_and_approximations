"""
  pisinger_to_mps.py
  NOTE: Please run me in python3 because I use FileNotFoundError (unsupported in 2)
  Given a file path to a pisinger KP instance *.csv and respective problem 
  number, this will create an equivalent instance in *.mps format.
  
  IMPORTANT:
    This assumes that the relevant files are going to be in ./problems/
    This assumes that the output files are to be written to ./problems_mps/

"""
import sys

def pisinger_to_mps(a_file_path, problem_no):
  # File validity check
  try:
    f = open("./problems/"+a_file_path, 'r')
  except FileNotFoundError:
    print("File "+a_file_path+" not found! Exiting...")
    sys.exit()
  
  # File is successfully opened, try to read from it.
  next_line = f.readline()
  
  # Deduce filename and problem stem
  filename = next_line[:-3]
  stem = next_line[:-2]

  # While problem_no is not found
  expected_problem_format = stem+str(problem_no)
  while next_line.rstrip() != expected_problem_format:
    next_line = f.readline()
    if next_line == '':
      print("Problem number "+str(problem_no)+" not found! Exiting...")
      sys.exit()

  # Get n
  next_line = f.readline()
  if next_line.split()[0] != "n":
    print("File format does not have n where I expected! Exiting...")
    sys.exit()
  n = int(next_line.split()[1])

  # Get capacity
  next_line = f.readline()
  if next_line.split()[0] != "c":
    print("File format does not have capacity where I expected! Exiting...")
    sys.exit()
  capacity = int(next_line.split()[1])
  
  # Move past z and time
  next_line = f.readline()
  assert next_line.split()[0] == "z", "Wait, where is z?"
  optimal = int(next_line.split()[1])
  next_line = f.readline()
  assert next_line.split()[0] == "time", "Wait, where is time?"
  
  # Start reading instances
  profits = []
  weights = []
  for i in range(n):
    next_line = f.readline()
    profits.append(next_line.split(",")[1])
    weights.append(next_line.split(",")[2])
  f.close() 

  # Write the mps file
  out_filename = "./problems_mps/"+expected_problem_format+".mps"
  file_out = open(out_filename, "w")
  file_out.write("NAME          "+filename+"\n")
  file_out.write("OBJSENSE\n    MAX\n")
  file_out.write("ROWS\n N  PROFIT\n L  CAPACITY\n")
  file_out.write("COLUMNS\n")
  for i in range(n):
    file_out.write("    x"+"{:<9}".format(str(i)))
    file_out.write("PROFIT"+"{:>17}".format(str(profits[i])))
    file_out.write("  CAPACITY             "+str(weights[i])+"\n")
  file_out.write("RHS\n")
  file_out.write("    RHS1      CAPACITY"+"{:>16}".format(str(capacity)+"\n"))
  file_out.write("RANGES\nBOUNDS\n")
  for i in range(n):
    file_out.write(" BV BINARY    x"+str(i)+"\n")
  file_out.write("ENDATA")
  file_out.close()

  # TODO Get rid of this after first use
  test_list = "all_4_500_10000.test"
  test_sols = "all_4_500_10000.solu"
  path_to_problems = "/home/nelsonfrew/branch_and_bound/problems_mps/"
  with open(test_list, "a") as f:
    f.write(path_to_problems + expected_problem_format + ".mps\n")
  with open(test_sols, "a") as f:
    f.write("=opt= "+"{:<30}".format(expected_problem_format)+"{:>11}".format(optimal)+"\n")


def main():
  #instance_types_easy = ["1", "2", "3", "4", "5", "6"]
  instance_types_easy = ["4"]
  #n_types_easy = ["50", "100", "200", "500", "1000", "2000", "5000", "10000"]
  n_types_easy = ["500"]
  #coefficient_types = ["1000", "10000", "100000", "1000000", "10000000"] 
  coefficient_types = ["10000"]
  #coefficient_types_nine = ["1000", "100000", "1000000"] 
  coefficient_types_nine = ["1000"]
  #instance_types_hard = ["11", "12", "13", "14", "15", "16"]
  instance_types_hard = ["11"]
  #n_types_hard = ["20", "50", "100", "200", "500", "1000", "2000", "5000",
  #                "10000"]
  n_types_hard = ["200"]
  for i in range(1, 101):
    # Easy instances
    for j in range(len(instance_types_easy)):
      for k in range(len(n_types_easy)):
        for l in range(len(coefficient_types)):
          csv_in = "knapPI_"+instance_types_easy[j]+"_"+n_types_easy[k]+"_" \
                   + coefficient_types[l]+".csv"
          pisinger_to_mps(csv_in, i)

    # Instance type 9
    #for k in range(len(n_types_easy)):
    #  for l in range(len(coefficient_types_nine)):
    #    csv_in = "knapPI_9_"+n_types_easy[k]+"_" \
    #             + coefficient_types_nine[l]+".csv"
    #    pisinger_to_mps(csv_in, i)

    # Hard instances
    #for j in range(len(instance_types_hard)):
    #  for k in range(len(n_types_hard)):
    #    csv_in = "knapPI_"+instance_types_hard[j]+"_"+n_types_hard[k]+"_10"\
    #             +"00.csv"
    #    pisinger_to_mps(csv_in, i)

if __name__ == "__main__":
  main()

