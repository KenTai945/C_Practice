int lengthOfLongestSubstring(char* s) 
{
	int ans = 0, left = 0, len = strlen(s);
	int last[256];						//用作紀錄每個char上次出現的index
	memset(last, -1, sizeof(last));		//初始化為-1 意義為尚未出現

	for (int i = 0; i < len; i++) 
	{
		if (last[s[i]] >= left)			// 上次s[i]出現的位置 >= 左邊邊界
			left = last[s[i]] + 1;
		last[s[i]] = i;
		ans = (ans) > (i - left + 1) ? (ans) : (i - left + 1);
	}
	return ans;
}
