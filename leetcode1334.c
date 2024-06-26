/*
 *Yihan Lu
 *https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
 */
int findTheCity (int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
	int i, j, k;
	int cnt, ret, min;
	int dist[101][101];

	for(i = 0; i < n; i++) {
		dist[i][i] = 0;
		for(j = i + 1; j < n; j++) {
			dist[i][j] = dist[j][i] = 10001;
		}
	}

	for(k = 0; k < edgesSize; k++) {
		dist[edges[k][0]][edges[k][1]] =  dist[edges[k][1]][edges[k][0]] = edges[k][2];
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	min = ret = 101;
	for(i = 0; i < n; i++) {
		for(j = cnt = 0; j < n; j++) {
			if(dist[i][j] < distanceThreshold) {
				cnt++;
			}
		}
		if(cnt <= min) {
			min = cnt;
			ret = i;
		}
	}
	return ret;

}
