// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let ground = null;
	let N; // 땅의 길이
	let K; // 폭탄 횟수
	let cnt;
	const dr = [0,-1, +1, 0, 0];
	const dc = [0, 0, 0,-1, +1];
	for await (const line of rl) {
		const inputs = line.trim().split(/\s+/).map((e) => +e);
		if(!N && !K) {
			[N, K] = inputs;
			cnt = K;
			ground = Array.from(Array(N+1), () => Array(N+1).fill(0));
		}
		else{
			const [row, col] = inputs;
			for(let i=0; i<dr.length; i++){
				const r = row+dr[i];
				const c = col+dc[i];
				if(isValid(r,c)){
					ground[r][c]++;
				}
			}
			cnt--;
		}
		if(cnt === 0){
			console.log(getBombSum());
			rl.close();
		}
	}
	
	function isValid(row, col){
		if(1<=row && row <= N && 1<=col && col <= N)
			return true;
		return false;
	}
	function getBombSum(){
		let sum = 0;
		for(let r=1; r<=N; r++){
			for(let c=1; c<=N; c++){
				sum += ground[r][c];
			}
		}
		return sum;
	}
	
	process.exit();
})();
