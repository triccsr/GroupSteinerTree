#pragma once


void graph_hash_of_mixed_weighted_ec_update_pairwise_jaccard_distance(graph_hash_of_mixed_weighted& input_graph) {

	/*time complexity: O(|V|+|E|)*/

	/*for introducing this distance: https://en.wikipedia.org/wiki/Jaccard_index ;
	The Jaccard distance, which measures dissimilarity between sample sets, is complementary
	to the Jaccard coefficient and is obtained by subtracting the Jaccard coefficient from 1;
	dist(i,j) = 1 - |V_i \cap V_j| / |V_i \cup V_j|, where V_i is the set of adjacent vertices of i;
	this is different from that in T Lappse's 2009 paper */

	/*time complexity: O(|V|+|E|)*/
	for (auto it1 = input_graph.hash_of_vectors.begin(); it1 != input_graph.hash_of_vectors.end(); it1++) {
		int i = it1->first;

		auto search = input_graph.hash_of_hashs.find(i);
		if (search != input_graph.hash_of_hashs.end()) {
			for (auto it2 = search->second.begin(); it2 != search->second.end(); it2++) {
				int j = it2->first;
				if (i < j) { // edge (i,j)
					/*update_pairwise_Jaccard_distance for edge (i,j)*/
					int V_i_cap_V_j = 0;
					auto search3 = input_graph.hash_of_hashs.find(i);
					if (search3 != input_graph.hash_of_hashs.end()) {
						for (auto it3 = search3->second.begin(); it3 != search3->second.end(); it3++) {
							int k = it3->first;
							if (graph_hash_of_mixed_weighted_contain_edge(input_graph, j, k)) { // k is also adjacenct to j
								V_i_cap_V_j++;
							}
						}
					}
					else {
						auto search4 = input_graph.hash_of_vectors.find(i);
						for (auto it2 = search4->second.adj_vertices.begin(); it2 != search4->second.adj_vertices.end(); it2++) {
							int k = it2->first;
							if (graph_hash_of_mixed_weighted_contain_edge(input_graph, j, k)) { // k is also adjacenct to j
								V_i_cap_V_j++;
							}
						}
					}
					int V_i_cup_V_j = graph_hash_of_mixed_weighted_degree(input_graph, i) + graph_hash_of_mixed_weighted_degree(input_graph, j) - V_i_cap_V_j;
					double ec = 1 - (double)V_i_cap_V_j / V_i_cup_V_j;
					graph_hash_of_mixed_weighted_add_edge(input_graph, i, j, ec);// update_pairwise_jaccard_distance for edge (j,i)
				}
			}
		}
		else {
			auto search2 = input_graph.hash_of_vectors.find(i);
			for (auto it2 = search2->second.adj_vertices.begin(); it2 != search2->second.adj_vertices.end(); it2++) {
				int j = it2->first;
				if (i < j) { // edge (i,j)
					/*update_pairwise_Jaccard_distance for edge (i,j)*/
					int V_i_cap_V_j = 0;
					auto search3 = input_graph.hash_of_hashs.find(i);
					if (search3 != input_graph.hash_of_hashs.end()) {
						for (auto it3 = search3->second.begin(); it3 != search3->second.end(); it3++) {
							int k = it3->first;
							if (graph_hash_of_mixed_weighted_contain_edge(input_graph, j, k)) { // k is also adjacenct to j
								V_i_cap_V_j++;
							}
						}
					}
					else {
						auto search4 = input_graph.hash_of_vectors.find(i);
						for (auto it2 = search4->second.adj_vertices.begin(); it2 != search4->second.adj_vertices.end(); it2++) {
							int k = it2->first;
							if (graph_hash_of_mixed_weighted_contain_edge(input_graph, j, k)) { // k is also adjacenct to j
								V_i_cap_V_j++;
							}
						}
					}
					int V_i_cup_V_j = graph_hash_of_mixed_weighted_degree(input_graph, i) + graph_hash_of_mixed_weighted_degree(input_graph, j) - V_i_cap_V_j;
					double ec = 1 - (double)V_i_cap_V_j / V_i_cup_V_j;
					graph_hash_of_mixed_weighted_add_edge(input_graph, i, j, ec);// update_pairwise_jaccard_distance for edge (j,i)
				}
			}
		}
	}

}


