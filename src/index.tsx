interface IRNHashing {
  sha256: (input: string) => string;
  md5: (input: string) => string;
}

declare global {
  const RNHashing: IRNHashing;
}

export const sha256 = RNHashing.sha256;
export const md5 = RNHashing.md5;
