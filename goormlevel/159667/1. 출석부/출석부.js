// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let N;
	let K;
	const nameHeights = []
	for await (const line of rl) {
		const input = line.trim().split(' ');
		if(!N && !K) {
			[N, K] = input;
		}
		else {
			nameHeights.push(input);
			N--;
		}
		
		if(N === 0)
			rl.close();
	}
	
	nameHeights.sort((a,b) => {
		if(a[0] < b[0]) return -1;
		else if (a[0] > b[0]) return 1;
		else return a[1] - b[1];
	});
	const result = nameHeights[K-1];
	console.log(`${result[0]} ${result[1]}`);
	
	process.exit();
})();
