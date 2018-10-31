# We generated outfiles.txt, which was a big file I sent to myself
#  which has all the nodes, runtimes, and DBs from SCIP
# This creates a shell command to run the branch_and_bound_app script
#  for each one which we found in SCIP that didn't immediately presolve.


def render_bounds_shell_script():
  with open("outfiles.txt", "r") as f:
    a_str = f.readline()
    while(a_str.split()[0] != "END"):
      problem_no = a_str.split("_")[-1].rstrip()
      # Ignore all instances with n > 200 items
      if int(a_str.split("_")[2]) > 200:
        f.readline()
        f.readline()
        f.readline()
        a_str = f.readline()
        continue
      if int(problem_no) < 10:
        instance = a_str[:-3]
      else:
        instance = a_str[:-4]
      dp_types = ["-ws", "-vv"]
      db_types = ["1", "3", "4"]
      for dp in dp_types:
        for db in db_types:
          command = "./branch_and_bound_app "+instance+".csv "+problem_no+" "+dp+" none 0.0 "+db+" -tb\n"
          with open("run_bnb_apps.sh", "a") as g:
            g.write(command)
      f.readline()
      f.readline()
      f.readline()
      a_str = f.readline()

render_bounds_shell_script()
