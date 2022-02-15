interface IRNHashing {
  sha256: (input: string) => string;
}

declare global {
  const RNHashing: IRNHashing;
}

export const sha256 = RNHashing.sha256;
