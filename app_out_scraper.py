# This file works with the file produced by branch_and_bound_app
#  which contains all the relevant data i need for analysing performance
# It produces a set of average decreases:
#   From A priori to a posteriori
#   From LP to A posteriori
# for each DP strategy

import numpy as np
# Information I want by the end of this:
#   Average decrease in node count between a priori and a posteriori
#   Average decrease in dual between a priori and a posteriori
#   Average decrease in node count between a posteriori and LP w/ VV
#   Average decrease in dual bound between a posteriori and LP w/ VV
#   Average decrease in node count between a posteriori and LP w/ WS
#   Average decrease in dual bound between a posteriori and LP w/ WS


def app_out_scraper():
  # Open app_out.csv
  with open("app_out.csv", "r") as f:
    a_priori_ws_node_counts = []
    a_priori_vv_node_counts = []
    a_priori_ws_dual_bounds = []
    a_priori_vv_dual_bounds = []
    LP_node_counts = []
    LP_dual_bounds = []
    a_posteriori_vv_node_counts = []
    a_posteriori_vv_dual_bounds = []
    a_posteriori_ws_node_counts = []
    a_posteriori_ws_dual_bounds = []

    # For each problem, read data into different lists
    line = f.readline()    
    while line.split()[0].rstrip() != "END":
      # First is WS a priori
      if int(line.split(", ")[4]) == 0:
        a_priori_ws_node_counts.append(int(line.split(", ")[4])+1)
      else:
        a_priori_ws_node_counts.append(int(line.split(", ")[4]))
      a_priori_ws_dual_bounds.append(int(line.split(", ")[5]))

      # Second is WS a posteriori
      line = f.readline()
      if int(line.split(", ")[4]) == 0:
        a_posteriori_ws_node_counts.append(int(line.split(", ")[4])+1)
      else:
        a_posteriori_ws_node_counts.append(int(line.split(", ")[4]))
      
      a_posteriori_ws_dual_bounds.append(int(line.split(", ")[5]))

      # Third is LP
      line = f.readline()

      # Fourth is VV a priori
      line = f.readline()
      if int(line.split(", ")[4]) == 0:
        a_priori_vv_node_counts.append(int(line.split(", ")[4])+1)
      else:
        a_priori_vv_node_counts.append(int(line.split(", ")[4]))
      a_priori_vv_dual_bounds.append(int(line.split(", ")[5]))

      # Fifth is VV a posteriori
      line = f.readline()
      if int(line.split(", ")[4]) == 0:
        a_posteriori_vv_node_counts.append(int(line.split(", ")[4])+1)
      else:
        a_posteriori_vv_node_counts.append(int(line.split(", ")[4]))
      a_posteriori_vv_dual_bounds.append(int(line.split(", ")[5]))

      # Sixth is LP again
      line = f.readline()
      if int(line.split(", ")[4]) == 0:
        LP_node_counts.append(int(line.split(", ")[4])+1)
      else:
        LP_node_counts.append(int(line.split(", ")[4]))
      LP_dual_bounds.append(int(line.split(", ")[5]))
      
      # Progress to first of the next lot
      line = f.readline()
      
      

  assert len(a_priori_ws_node_counts) == len(a_priori_vv_node_counts)
  assert len(LP_node_counts) == len(a_priori_vv_node_counts)
  assert len(a_priori_vv_node_counts) == len(a_priori_ws_dual_bounds) 
  assert len(a_priori_ws_dual_bounds) == len(a_priori_vv_dual_bounds)
  assert len(LP_dual_bounds) == len(a_priori_vv_dual_bounds)
  assert len(a_posteriori_ws_dual_bounds) == len(a_priori_vv_dual_bounds)

  # At this point we should have a bunch of parallel lists
  percentage_changes_a_priori_aposteriori_ws_nodes = []
  percentage_changes_a_priori_aposteriori_vv_nodes = []
  percentage_changes_a_priori_aposteriori_ws_duals = []
  percentage_changes_a_priori_aposteriori_vv_duals = []
  percentage_changes_aposteriori_LP_ws_nodes = []
  percentage_changes_aposteriori_LP_vv_nodes = []
  percentage_changes_aposteriori_LP_ws_duals = []
  percentage_changes_aposteriori_LP_vv_duals = []

  for i in range(len(a_priori_ws_node_counts)):
    if (a_priori_ws_dual_bounds[i] < a_posteriori_ws_dual_bounds[i]):
      print("WS: A priori was better at "+str(i))
    if (a_priori_vv_dual_bounds[i] < a_posteriori_vv_dual_bounds[i]):
      print("VV: A priori was better at "+str(i))

    # ws a priori to a posteriori node change
    difference = a_priori_ws_node_counts[i] - a_posteriori_ws_node_counts[i]
    perc_decrease = (difference / a_priori_ws_node_counts[i]) * 100
    percentage_changes_a_priori_aposteriori_ws_nodes.append(perc_decrease)

    # vv a priori to a posteriori node change
    difference = a_priori_vv_node_counts[i] - a_posteriori_vv_node_counts[i]
    perc_decrease = (difference / a_priori_vv_node_counts[i]) * 100
    percentage_changes_a_priori_aposteriori_vv_nodes.append(perc_decrease)

    # ws a priori to a posteriori dual change
    difference = a_priori_ws_dual_bounds[i] - a_posteriori_ws_dual_bounds[i]
    perc_decrease = (difference / a_priori_ws_dual_bounds[i]) * 100
    percentage_changes_a_priori_aposteriori_ws_duals.append(perc_decrease)

    # vv a priori to a posteriori dual change
    difference = a_priori_vv_dual_bounds[i] - a_posteriori_vv_dual_bounds[i]
    perc_decrease = (difference / a_priori_vv_dual_bounds[i]) * 100
    percentage_changes_a_priori_aposteriori_vv_duals.append(perc_decrease)

    # ws a posteriori to LP node change
    difference = LP_node_counts[i] - a_posteriori_ws_node_counts[i] 
    perc_decrease = (difference / LP_node_counts[i]) * 100
    percentage_changes_aposteriori_LP_ws_nodes.append(perc_decrease)

    # vv a posteriori to LP node change
    difference = LP_node_counts[i] - a_posteriori_vv_node_counts[i] 
    perc_decrease = (difference / LP_node_counts[i]) * 100
    percentage_changes_aposteriori_LP_vv_nodes.append(perc_decrease)

    # ws a posteriori to LP dual change
    difference = LP_dual_bounds[i] - a_posteriori_ws_dual_bounds[i] 
    perc_decrease = (difference / LP_dual_bounds[i]) * 100
    percentage_changes_aposteriori_LP_ws_duals.append(perc_decrease)
    
    # vv a posteriori to LP dual change
    difference = LP_dual_bounds[i] - a_posteriori_vv_dual_bounds[i] 
    perc_decrease = (difference / LP_dual_bounds[i]) * 100
    percentage_changes_aposteriori_LP_vv_duals.append(perc_decrease)

  avg_ws_apriori_aposteriori_node_dec = np.mean(percentage_changes_a_priori_aposteriori_ws_nodes)
  avg_vv_apriori_aposteriori_node_dec = np.mean(percentage_changes_a_priori_aposteriori_vv_nodes)
  avg_ws_apriori_aposteriori_dual_dec = np.mean(percentage_changes_a_priori_aposteriori_ws_duals)
  avg_vv_apriori_aposteriori_dual_dec = np.mean(percentage_changes_a_priori_aposteriori_vv_duals)
  avg_ws_aposteriori_LP_node_dec = np.mean(percentage_changes_aposteriori_LP_ws_nodes)
  avg_vv_aposteriori_LP_node_dec = np.mean(percentage_changes_aposteriori_LP_vv_nodes)
  avg_ws_aposteriori_LP_dual_dec = np.mean(percentage_changes_aposteriori_LP_ws_duals)
  avg_vv_aposteriori_LP_dual_dec = np.mean(percentage_changes_aposteriori_LP_vv_duals)

  print("Average % decrease in nodes from a priori to a posteriori (WS): "+str(avg_ws_apriori_aposteriori_node_dec))
  print("Average % decrease in nodes from a priori to a posteriori (VV): "+str(avg_vv_apriori_aposteriori_node_dec))
  print("Average % decrease in duals from a priori to a posteriori (WS): "+str(avg_ws_apriori_aposteriori_dual_dec))
  print("Average % decrease in duals from a priori to a posteriori (VV): "+str(avg_vv_apriori_aposteriori_dual_dec))
  print("Average % decrease in nodes from a posteriori to LP (WS): "+str(avg_ws_aposteriori_LP_node_dec))
  print("Average % decrease in nodes from a posteriori to LP (VV): "+str(avg_vv_aposteriori_LP_node_dec))
  print("Average % decrease in duals from a posteriori to LP (WS): "+str(avg_ws_aposteriori_LP_dual_dec))
  print("Average % decrease in duals from a posteriori to LP (VV): "+str(avg_vv_aposteriori_LP_dual_dec))

app_out_scraper()
