// cout << "ind: " << ind << '\n';
                        while(arr[0].first < arr[ind].first and ind < n){
                            arr[ind].first = ceil((float)arr[ind].first/arr[0].first);
                            pairs.push_back({arr[ind].second+1, arr[0].second+1});
                            if(arr[ind].first == arr[0].first)
                                ind++;
                        }
                        //cout << "ind val: " << arr[ind].first << '\n';
                        if(ind == n) ind--;
                        //cout << "here: " << arr[ind].first << '\n';
                        if(arr[ind].first != 2 and arr[0].first != arr[ind].first){
                           // cout << "here again " << '\n';
                            while(arr[0].first > arr[ind].first){
                                arr[0].first = ceil((float)arr[0].first/arr[ind].first);
                                pairs.push_back({arr[0].second+1, arr[ind].second+1});
                                
                            }
                            //cout << arr[0].first << " first's" << '\n';
                            two = 0;
                        }else two = ind;
                        if(arr[0].first != arr[n-1].first){
                            for(int i = n-1; i>=0; i--){
                                if(arr[i].first != arr[two].first){
                                    //cout << "entered with: " << arr[i].second+1 << "--" << arr[ind].second << "\n";
                                    while(arr[i].first > arr[two].first){
                                        arr[i].first = ceil((float)arr[i].first/arr[two].first);
                                        pairs.push_back({arr[i].second+1, arr[two].second+1});
                                        //cout << arr[i].second+1 << " " << ind + 1 <<'\n';
                                    }
                                }
                            }
                        }