import inspect
import os
from pathlib import Path

import torch


def torch_load(path, map_location=None, **kwargs):
    """Load legacy checkpoints across PyTorch versions.

    PyTorch 2.6 changed the default of weights_only to True. This project uses
    older training checkpoints that may contain non-tensor metadata, so keep the
    historical loading behavior unless the caller explicitly overrides it.
    """
    if "weights_only" not in kwargs and "weights_only" in inspect.signature(torch.load).parameters:
        kwargs["weights_only"] = False
    if map_location is not None:
        kwargs["map_location"] = map_location
    return torch.load(path, **kwargs)


def load_local_env(filename=".env.local"):
    """Load local KEY=VALUE settings without overriding exported env vars."""
    env_path = Path(__file__).resolve().parent / filename
    if not env_path.exists():
        return

    for raw_line in env_path.read_text().splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, value = line.split("=", 1)
        key = key.strip()
        value = value.strip().strip('"').strip("'")
        if key and key not in os.environ:
            os.environ[key] = value
